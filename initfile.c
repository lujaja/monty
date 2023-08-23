#include "monty.h"
/**
 * initializer - function
 * @g_vr: pointer
 *
 * Return: 0 success 1 fail
 * Description: initializer
 */
int initializer(g_var *g_vr)
{
	g_vr->fd = NULL;
	g_vr->buffer = NULL;
	g_vr->status = 0;
	g_vr->line_number = 1;
	g_vr->M = 0;

	return (EXIT_SUCCESS);
}
