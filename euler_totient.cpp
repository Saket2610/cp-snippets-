std::vector<int> phi(n + 1);
std::iota(phi.begin(), phi.end(), 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            phi[j] -= phi[i];
        }
    }
// The black box
// Input: a number n
// Output: an array phi where phi[m] = the count of numbers from 1 to m that share no common factor with m (other than 1). This is called Euler’s totient, φ(m).
// m    	numbers from 1..m     coprime to m	φ(m)
// 1	    1	                    1
// 2	    1	                    1
// 3	    1, 2	                2
// 4	    1, 3	                2
// 6	    1, 5	                2
// 7	    1, 2, 3, 4, 5, 6	    6

 // The sum of the totient values of all positive divisors \(d\) of \(n\) equals \(n\) itself:

// the gcd is the sum of φ(d) over all common divisors d of x and y.

