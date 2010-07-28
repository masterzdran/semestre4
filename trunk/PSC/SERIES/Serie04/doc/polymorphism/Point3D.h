/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * Point3D: versão C da classe Point3D
 *
 * Uma vez que em C não existe suporte para herança utiliza-se
 * composição, integrando directamente uma instância de Point
 * como primeiro campo de Point3D. Desta forma, o endereço da
 * instância de Point3D coincide com o endereço da instância de
 * Point que aquela contém.
 *
 * Os "métodos" herdados e não redefinidos (getX e getY) são
 * invocados via macros.
 */

#ifndef POINT3D_H
#define POINT3D_H

#include "Point.h"

typedef struct Point3D_tag {
	/* Um Point3D TEM_UM Point, em vez de Point3D É_UM Point. */
	Point super;
	int z;
} Point3D;

/* Inicialização de instâncias de Point3D */
#define init_Point3D(this,name) init_Point3D_XYZ((Point3D * const)(this), 0, 0, 0, name)
void    init_Point3D_XYZ(Point3D * this, int x, int y, int z, const char * name);

/* Finalização de instâncias de Point3D (só finaliza a base, uma vez que não há outros recursos a gerir). */
#define cleanup_Point3D(this) cleanup_Point(&(((Point3D * const)(this))->super))

/* Point3D_getX e Point3D_getY recorrem directamente às definições da base. */
#define Point3D_getX(this)  Point_getX(((const Point3D * const)(this))->super)
#define Point3D_getY(this)  Point_getY(((const Point3D * const)(this))->super)
#define Point3D_getZ(this)  (((const Point3D * const)(this))->z)

#define Point3D_getName(this) Point_getName(((const Point3D * const)(this))->super)

/* Point3D_translate é uma sobrecarga e Point3D_magnitude e Poin3D_print são redefinições. */
void    Point3D_translate(Point3D * this, int dx, int dy, int dz);
double  Point3D_magnitude(const Point3D * this);
void    Point3D_print(const Point3D * this);

/* Alocação dinâmica de instâncias de Point3D. */
Point3D * new_Point3D(const char * name);
Point3D * new_Point3D_XYZ(int x, int y, int z, const char * name);

/* Libertação de instâncias de Point3D alocadas dinamicamente. */
void delete_Point3D(Point3D * this);

#endif /* POINT3D_H */
