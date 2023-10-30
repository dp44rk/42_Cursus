#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p ) {
    Vec ab(b - a), ap(p - a),
        bc(c - b), bp(p - b),
        ca(a - c), cp(p - c);
    
    if ((ab * ap > Fixed(0) && bc * bp > Fixed(0) && ca * cp > Fixed(0))
        || (ab * ap < Fixed(0) && bc * bp < Fixed(0) && ca * cp < Fixed(0)))
        return true;
    return false;
}