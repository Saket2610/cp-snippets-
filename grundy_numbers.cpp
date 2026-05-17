// XOR = 0 losing position
// XOR != 0 winning position 
// position for the player whose turn it is
int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        ans ^= a;
}
// if(ans != 0 ) alice wins 
// else bob wins 
