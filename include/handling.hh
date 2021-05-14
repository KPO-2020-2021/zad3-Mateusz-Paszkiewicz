#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>

#include"rectangle.hh"
#include"vector.hh"

bool CoordsReadFromFile(const char *, Rectangle &);

void CoordsToStream(std::ostream&, Rectangle &);

bool SaveCoordsToFile( const char *,  Rectangle &);
