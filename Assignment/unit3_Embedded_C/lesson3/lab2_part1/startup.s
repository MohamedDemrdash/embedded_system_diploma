/* startup for cortex-m3
 * Eng. Mohamed Hussein Demrdash
 */

.section .vectores

.word 0x20001000 /* The top of the stack (SP)*/
.word vectore_handler /* Reset handler */

.section .text

reset:
	bl main
stop:
	b stop

vectore_handler:
	bl reset

.thumb_func