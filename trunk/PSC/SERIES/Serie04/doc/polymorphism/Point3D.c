/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * Point3D: versão C da classe Point3D
 */

#include "Point3D.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static const PointMethods Point3D_vtable = {
	"Point3D",
	sizeof(Point3D),
	(double (*)(const Point *))Point3D_magnitude,
	(void   (*)(const Point *))Point3D_print
};

void init_Point3D_XYZ(Point3D * this, int x, int y, int z, const char * name) {
	/* Invocação explícita de função de inicialização da base. */
	init_Point_XY(&(this->super), x, y, name);
	this->super.vptr = &Point3D_vtable;
	this->z = z;
}

void Point3D_translate(Point3D * this, int dx, int dy, int dz) {
	/* Invocação de código definido na base. */
	Point_translate(&(this->super), dx, dy);
	this->z += dz;
}

double Point3D_magnitude(const Point3D * this) {
	return sqrt((double)(this->super.x) * (this->super.x) + (double)(this->super.y) * (this->super.y) + (double)(this->z) * (this->z));
}

void Point3D_print(const Point3D * this) {
	printf("{ name = \"%s\"; x = %d; y = %d; z = %d }\n",
	       this->super.name ? this->super.name : "",
	       this->super.x, this->super.y, this->z);
}

Point3D * new_Point3D(const char * name) {
	Point3D * p = (Point3D *)malloc(sizeof(Point3D)); /* Alocação dinâmica do espaço. */
	init_Point3D(p, name);                            /* Inicialização da instância.  */
	return p;
}

Point3D * new_Point3D_XYZ(int x, int y, int z, const char * name) {
	Point3D * p = (Point3D *)malloc(sizeof(Point3D)); /* Alocação dinâmica do espaço. */
	init_Point3D_XYZ(p, x, y, z, name);               /* Inicialização da instância.  */
	return p;
}

void delete_Point3D(Point3D * this) {
	if (this != NULL) {
		cleanup_Point3D(this);                        /* Finalização da instância.     */
		free(this);                                   /* Libertação do espaço alocado. */
	}
}
