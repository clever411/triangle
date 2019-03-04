#include <cmath>
#include <iostream>

#include "geometry.cpp"


using namespace std;





// functions
inline double get_cos(double a, double b, double c)
{
	return
		( -a*a + b*b + c*c ) /
		( 2*b*c );
}

inline double get_angle(double a, double b, double c)
{
	return acos( get_cos(a, b, c) );
}

inline double get_height(double b, double ac)
{
	return b*sin(ac);
}

inline double get_median(double aa, double b, double c)
{
	return hypot( sin(aa)*c, b/2 - cos(aa)*c );
}

inline double get_bisector(double aa, double ab, double c)
{
	return c * sin(ab) / sin( M_PI - ab - aa/2 );
}





// main
int main( int argc, char *argv[] )
{
	double
		a, b, c,
	        aa, ab, ac,
		ha, hb, hc,
		ma, mb, mc,
		ba, bb, bc,
		P, S, R, r;
		


	// input
	cout << "Hello! My name is 'Triangle Calculater 1.0'\n"
		"Enter sides: a, b, c: ";
	cin >> a >> b >> c;



	// calc
		// angle
	aa = get_angle(a, b, c);
	ab = get_angle(b, a, c);
	ac = get_angle(c, a, b);

		// height
	ha = get_height(b, ac);
	hb = get_height(a, ac);
	hc = get_height(a, ab);

		// medians
	ma = get_median(ab, a, c);
	mb = get_median(aa, b, c);
	mc = get_median(aa, c, b);

		// bisectors
	ba = get_bisector(aa, ab, c);
	bb = get_bisector(ab, aa, c);
	bc = get_bisector(ac, aa, b);

		// perimeter, square
	P = a + b + c;
	S = a*ha/2.0;
	R = a/2.0/sin(aa);
	r = S*2/P;



	// output
	cout << "Sides:\n";
	cout << "a = " << a << '\n';
	cout << "b = " << b << '\n';
	cout << "c = " << c << '\n';
	cout << endl;

	cout << "Angles:\n";
	cout << "A = " << todegree(aa) << '\n';
	cout << "B = " << todegree(ab) << '\n';
	cout << "C = " << todegree(ac) << '\n';
	cout << endl;

	cout << "Heights:\n";
	cout << "AH = " << ha << '\n';
	cout << "BH = " << hb << '\n';
	cout << "CH = " << hc << '\n';
	cout << endl;

	cout << "Medians:\n";
	cout << "AM = " << ma << '\n';
	cout << "BM = " << mb << '\n';
	cout << "CM = " << mc << '\n';
	cout << endl;

	cout << "Bisectors:\n";
	cout << "AN = " << ba << '\n';
	cout << "BN = " << bb << '\n';
	cout << "CN = " << bc << '\n';
	cout << endl;

	cout << "Perimeter = " << P << '\n';
	cout << "Square = " << S << '\n';
	cout << "R = " << R << '\n';
	cout << "r = " << r << '\n';



	return 0;
}





// end
