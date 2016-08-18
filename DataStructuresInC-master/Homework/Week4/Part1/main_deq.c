#include <stdio.h>
#include <stdlib.h>
#include "cirListDeq.h"

int main () {
	struct cirListDeque testDeque;

	printf("Testing Deque ADT based on Circularly-Doubly-Linked List \n");
	/*Initialize the deque */
	initCirListDeque(&testDeque);
	/*Add 3 to the back */
	addBackCirListDeque(&testDeque, 3);
	/*Add 4 to the back */
	addBackCirListDeque(&testDeque, 4);
	/*Add 5 to the back */
	addBackCirListDeque(&testDeque, 5);

	/*Should print 3.0  4.0  5.0 */
	printCirListDeque(&testDeque);
	
	/*Add 2 to the front */
	addFrontCirListDeque(&testDeque, 2);
	/*Add 1 to the front */
	addFrontCirListDeque(&testDeque, 1);

	/*Should print 1.0, 2.0, 3.0,  4.0,  5.0 */
	printCirListDeque(&testDeque);

	/*Should print front: 5.0; back: 1.0 */
	printf("front: %g; back: %g\n\n", frontCirListDeque(&testDeque), backCirListDeque(&testDeque));
	/*Remove the back of the deque */
	removeBackCirListDeque(&testDeque);
	/*Should print front: 5.0; back: 2.0 */
	printf("front: %g; back: %g\n\n", frontCirListDeque(&testDeque), backCirListDeque(&testDeque));
	/*Remove the front of the deque */
	removeFrontCirListDeque(&testDeque);
	/*Should print front: 4.0; back: 2.0 */
	printf("front: %g; back: %g\n\n", frontCirListDeque(&testDeque), backCirListDeque(&testDeque));
	freeCirListDeque(&testDeque);

	return EXIT_SUCCESS;
}
