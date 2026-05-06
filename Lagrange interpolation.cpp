// Lagrange interpolation centre of mass on x axis 

// A polynomial 𝐴(𝑥) of degree 𝑑 is an expression of the form 𝐴(𝑥)=𝑎0x0+𝑎1𝑥+𝑎2𝑥2+⋯+𝑎𝑑𝑥𝑑, 
  
for (int i = 0; i <= d; i++) {
    std::cin >> a[i];
}

auto get = [&](auto a) {
        Z v0 = 0, v1 = 0;
        Z sum = 1LL * d * (d + 1) / 2;
        for (int i = 0; i <= d; i++) {
        Z c = comb.invfac(i) * comb.invfac(d - i) * ((d - i) % 2 ? -1 : 1);
        v0 += c * a[i];
        v1 += c * a[i] * -(sum - i);
    }
    return v1 / v0 / d;
};
get(a);
