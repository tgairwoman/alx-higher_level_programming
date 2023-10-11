#include <Python.h>
#include <stdio.h>

void print_python_bytes(PyObject *p);
void print_python_list(PyObject *p);

/**
 * print_python_bytes - Prints information about Python bytes objects
 * @p: PyObject bytes object
 *
 * Return: None
 */
void print_python_bytes(PyObject *p)
{
	PyBytesObject *bytes = (PyBytesObject *)p;
	Py_ssize_t size, i;
	char *string;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(bytes))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	string = PyBytes_AsString(p);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", string);

	printf("  first %ld bytes:", (size + 1 > 10) ? 10 : size + 1);
	for (i = 0; i < size + 1 && i < 10; i++)
		printf(" %02x", string[i] & 0xff);
	printf("\n");
}

/**
 * print_python_list - Prints information about Python lists
 * @p: PyObject list
 *
 * Return: None
 */
void print_python_list(PyObject *p)
{
	PyListObject *list = (PyListObject *)p;
	Py_ssize_t size, allocated, i;
	PyObject *item;

	printf("[*] Python list info\n");
	size = PyList_Size(p);
	allocated = list->allocated;

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", allocated);

	for (i = 0; i < size; i++)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}
