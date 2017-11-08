//FFT
#include <bits/stdc++.h>
#include <complex>
#include <valarray>
using namespace std;
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
void fft(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;
    CArray even = x[std::slice(0, N/2, 2)];
    CArray  odd = x[std::slice(1, N/2, 2)];
    fft(even);
    fft(odd);
    for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}
int main()
{
	int n;
	cout<<"Enter the size of polynomial\n";
	cin>>n;
    Complex test[n];
    for(int o=0;o<n;o++){
    	double t;
    	cin>>t;
    	Complex x(t,0);
    	test[o]=x;
	}
    CArray data(test, 8);
    fft(data);
 
    std::cout << "fft" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << data[i] << std::endl;
    }
}
