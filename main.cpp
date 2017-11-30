/** Coordinate Conversion
 *  Computer Programming
 *  C00187998
 *  Gerard Murphy
 *  09/10/17
 */

#include <iostream>
#include <math.h>/**< preprocessor directives */

using namespace std;

void cart_2_pol(float x, float y, float *ptr_r, float *ptr_ang);/**< function prototypes */
void pol_2_cart(float r, float ang, float *ptr_x, float *ptr_y);

int main()/**< main() function */
{
    cout << "Coordinate Conversion" << endl;/**< Title */

    char Input;/**< variable declarations */

    float x=0, y=0, r=0, ang=0;
    float *ptr_x, *ptr_y, *ptr_r, *ptr_ang;

    ptr_x=&x;
    ptr_y=&y;
    ptr_r=&r;
    ptr_ang=&ang;

     do/**< do while loop containing switch case */
{
        cout<<  "\n\n Choose from the following:"<<
                "\n'p' Cartesian to Polar coordinates"<<
                "\n'c' Polar to Cartesian coordinates"<<
                "\n'q' to quit program";
        cin>>Input;

    switch(Input)/**< switches between different operators */
    {
        case 'p':
                    cout<<"Enter values for x and y"<<endl;
                    cin>>x>>y;
                    cart_2_pol(x, y, ptr_r, ptr_ang);/**< call cart_2_pol function and display result below */
                    cout<<" \nThe magnitude is "<< *ptr_r <<endl;
                    cout<<" \nThe angle in radians is "<< *ptr_ang <<endl;

                    break;
        case 'c':
                    cout<<"Enter magnitude for r"<<endl;
                    cin>>r;
                    cout<<"Enter angle"<<endl;
                    cin>>ang;
                    pol_2_cart(r, ang, ptr_x, ptr_y);/**< call cart_2_pol function and display result below */
                    cout<<" \nThe x-coordinate is "<< *ptr_x <<endl;
                    cout<<" \nThe y-coordinate is "<< *ptr_y <<endl;

                    break;
        case 'q':
                    cout<<"quitting"<<endl;

                    break;

        default:
                    cout<<"Please try again"<<endl;

                    break;
    }
}

    while (Input!='q');

    return 0;
}

void cart_2_pol(float x, float y, float *ptr_r, float *ptr_ang)

{
    *ptr_r=sqrt(pow(x,2)+pow(y,2));/**< cartesian to polar calculations */
    *ptr_ang=atan(y/x);

    return;
}

void pol_2_cart(float r, float ang, float *ptr_x, float *ptr_y)

{
    *ptr_x=r*cos(ang);/**< polar to cartesian calculations */
    *ptr_y=r*sin(ang);

    return;
}
