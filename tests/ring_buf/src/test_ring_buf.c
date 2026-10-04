/*
 * Ring Buffer Module - Homework Test Skeleton
 *
 * test_fresh_state is provided as a worked example. Fill in the remaining
 * 7 ZTEST bodies according to TEST_SPEC.md. Stubs call ztest_test_skip()
 * so the binary builds and runs cleanly before each test is implemented.
 *
 * Run:
 *   west twister -T tests/ring_buf -p native_sim
 */

#include <zephyr/ztest.h>
#include <errno.h>

#include "ring_buf.h"

/*
 * Shared before hook: every suite reinitialises the ring buffer with a
 * capacity of 4 so tests start from a clean, known state. Capacity 4 is
 * enough to exercise FIFO order (push 1, 2, 3) and overflow (full at 4).
 */
static void before(void *f)
{
	ARG_UNUSED(f);
	rb_init(4);
}

/*
 * ============================================================================
 * Test Suite: ring_buf_init
 *
 * Initial state and re-initialization behaviour.
 * ============================================================================
 */
ZTEST_SUITE(ring_buf_init, NULL, NULL, before, NULL, NULL);

/* PROVIDED — study this test before writing the rest. */
ZTEST(ring_buf_init, test_fresh_state)
{
	zassert_true(rb_is_empty(), "Fresh buffer must be empty");
	zassert_equal(rb_count(), 0, "Fresh buffer count must be 0");
}

ZTEST(ring_buf_init, test_reinit_clears_state)
{
	rb_push(50);
	rb_init(4);
	zassert_true(rb_is_empty(), "Reinitialized buffer must be empty");
	zassert_equal(rb_count(), 0, "Reinitialized buffer count must be 0");
}

/*
 * ============================================================================
 * Test Suite: ring_buf_push_pop
 *
 * Single push/pop round-trip, FIFO order, full error path.
 * ============================================================================
 */
ZTEST_SUITE(ring_buf_push_pop, NULL, NULL, before, NULL, NULL);

ZTEST(ring_buf_push_pop, test_single_push_pop)
{
	int v;
	rb_push(42);
	rb_pop(&v);
	zassert_equal(v, 42, "Popped value must match pushed value");
	zassert_true(rb_is_empty(), "Buffer must be empty after single push/pop");
}

ZTEST(ring_buf_push_pop, test_fifo_order)
{
	int v;
	rb_push(1);
	rb_push(2);
	rb_push(3);
	rb_pop(&v);
	zassert_equal(v, 1, "First popped value must be 1");
	rb_pop(&v);
	zassert_equal(v, 2, "Second popped value must be 2");
	rb_pop(&v);
	zassert_equal(v, 3, "Third popped value must be 3");
}

ZTEST(ring_buf_push_pop, test_push_full_returns_enospc)
{
	rb_push(1);
	rb_push(2);
	rb_push(3);
	rb_push(4);
	zassert_equal(rb_push(5), -ENOSPC, "Pushing to a full buffer must return -ENOSPC");
}

/*
 * ============================================================================
 * Test Suite: ring_buf_boundaries
 *
 * Peek semantics and NULL-pointer boundary conditions.
 * ============================================================================
 */
ZTEST_SUITE(ring_buf_boundaries, NULL, NULL, before, NULL, NULL);

ZTEST(ring_buf_boundaries, test_peek_does_not_consume)
{
	int v;
	rb_push(7);
	rb_peek(&v);
	zassert_equal(v, 7, "Peeked value must match pushed value");
	rb_peek(&v);
	zassert_equal(v, 7, "Peeked value must still be 7");
	zassert_equal(rb_count(), 1, "Buffer count must still be 1");
}

ZTEST(ring_buf_boundaries, test_pop_null_returns_einval)
{
	zassert_equal(rb_pop(NULL), -EINVAL, "Popping to a NULL pointer must return -EINVAL");
}

ZTEST(ring_buf_boundaries, test_is_full_after_fill)
{
	rb_push(5);
	rb_push(6);
	rb_push(7);
	rb_push(8);
	zassert_true(rb_is_full(), "Buffer must be full after pushing 4 values");
	zassert_equal(rb_count(), 4, "Buffer count must be 4 after pushing 4 values");
}
