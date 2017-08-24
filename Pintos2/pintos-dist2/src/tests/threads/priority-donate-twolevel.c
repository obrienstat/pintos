/*
 * See Lab 2 Tutorial Slides for details
 */

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"

static thread_func b_thread_func;
static thread_func c_thread_func;
static thread_func d_thread_func;

static struct lock X, Y;

void test_priority_donate_twolevel(void) 
{
    thread_set_priority(1);

    lock_init(&X);
    lock_init(&Y);

    lock_acquire(&X);

    thread_create("Thread B", 2, b_thread_func, NULL);
    thread_create("Thread C", 4, c_thread_func, NULL);
    thread_create("Thread D", 3, d_thread_func, NULL);

    lock_release(&X);
    msg("Thread A finished.");
}

static void b_thread_func(void *aux UNUSED) 
{
    lock_acquire(&Y);
    lock_acquire(&X);
    lock_release(&X);
    lock_release(&Y);
    msg("%s finished.", thread_current()->name);
}

static void c_thread_func(void *aux UNUSED) 
{
    lock_acquire(&Y);
    lock_release(&Y);
    msg("%s finished.", thread_current()->name);
}


static void d_thread_func(void *aux UNUSED) 
{
    msg("%s finished.", thread_current()->name);
}