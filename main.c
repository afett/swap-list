#include <stdio.h>
#include <stdbool.h>

/*
 * via http://codinghighway.com/?p=991
 *
 * compile with gcc -std=c99 -Wall -pedantic -g %
 *
 * You are given a singly linked list:
 */
struct node {
	int n;
	struct node *next;
};

/*
 * Write a function that will swap pairs of elements in a given
 * singly-linked list. Note that you have to actually swap the elements
 * not just the values, and that you should modify the list in place
 * (i.e. you should not create a copy of the list).
 *
 * For instance, the list 1->2->3->4->5->6->… becomes 2->1->4->3->6->5->…
 *
 * IMPORTANT: Your implementation must also work for circular lists where
 * the tail is pointing back to the head of the list. You do not have
 * to check if the tail points to an intermediate (non-head) element.
 */
static struct node *swapPairs(struct node *l)
{
	struct node *swapped_list;

	swapped_list = l;
	return swapped_list;
}

static void dump(struct node *l)
{
	struct node *n;

	if (!l) {
		fprintf(stderr, "<empty>");
	}

	for (n = l; n != NULL; n = n->next) {
		fprintf(stderr, "%u -> ", n->n);
		if (!n->next) {
			fprintf(stderr, "(nil)");
		} else if (n->next == l) {
			fprintf(stderr, "(head)");
			break;
		}
	}
	fprintf(stderr, "\n");
}

/*
 * This function will initialize an array of the given size to be a
 * singly linked list as described above. the value n will be set from
 * 1 to size. If ring is true the last next pointer of the last element
 * will point to the first.
 */
static struct node* test_init(struct node *l, size_t size, bool ring)
{
	size_t i;

	if (size == 0) {
		return NULL;
	}

	for (i = 1; i < size; ++i) {
		l[i - 1].n = i;
		l[i - 1].next = &l[i];
	}

	l[i - 1].n = i;
	l[i - 1].next = ring ? &l[0] : NULL;

	return &l[0];
}

/*
 * fill a list of size n, possibly a ring
 * dump it to stderr, run the swapPairs()
 * function on it and dump rhe result.
 */
void test_run(struct node *n, size_t size, bool ring)
{
	struct node *l;

	fprintf(stderr, "%sring: %zu\n", (ring ? "" : "no "), size);
	l = test_init(n, size, ring);
	dump(l);
	l = swapPairs(l);
	dump(l);
	fprintf(stderr, "\n");
}

int main()
{
	struct node n[6];

	test_run(n, 0, false);

	test_run(n, 1, false);
	test_run(n, 2, false);
	test_run(n, 5, false);
	test_run(n, 6, false);

	test_run(n, 1, true);
	test_run(n, 2, true);
	test_run(n, 5, true);
	test_run(n, 6, true);

	return 0;
}
