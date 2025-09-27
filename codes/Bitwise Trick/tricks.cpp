bool isOdd(int x) {
    return x & 1;
}

int isolateRightmostSetBit(int x) {
    return x & -x;//取得最右邊的1
}

bool isPowerOfTwo(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

int countSetBits(int x) {
    int count = 0;
    while (x) {
        x &= (x - 1); // 清除最右邊的 1
        count++;
    }
    return count;
}

int turnOffRightmostSetBit(int x) {
    return x & (x - 1);//將最右邊的1設為0
}

int setBit(int x, int pos) {
    return x | (1 << pos);//設該位元為1
}

int clearBit(int x, int pos) {
    return x & ~(1 << pos);//設該位元為0
}

int toggleBit(int x, int pos) {
    return x ^ (1 << pos);//切換該位元
}

int getBit(int x, int pos) {
    return (x >> pos) & 1;//取得該位元值
}

int modPowerOfTwo(int x, int mod) {
    return x & (mod - 1);//x % mod, mod 必須是 2 的冪次
}

// a + b = ( a ^ b ) + 2 * ( a & b )
int add(int a, int b) {
    while (b != 0) {
        int carry = a & b; // 計算進位
        a = a ^ b;         // 無進位相加
        b = carry << 1;    // 將進位左移一位
    }
    return a;
}
// a - b = ( a ^ b ) - 2 * ( (~a) & b )
int subtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b; // 計算借位
        a = a ^ b;             // 無借位相減
        b = borrow << 1;       // 將借位左移一位
    }
    return a;
}
// a * b = sum( a << i ) for each set bit i in b
int multiply(int a, int b) {
    int result = 0;
    while (b > 0) {
        if (b & 1) { // 如果 b 的最低位是 1
            result = add(result, a); // 使用上面的加法函數
        }
        a <<= 1; // 將 a 左移一位 (相當於乘以 2)
        b >>= 1; // 將 b 右移一位 (相當於除以 2)
    }
    return result;
}
// a / b = sum( 1 << i ) for each set bit i in a
int divide(int a, int b) {
    if (b == 0) throw std::invalid_argument("Division by zero");
    int result = 0;
    int power = 1;
    int tempB = b;

    while (tempB <= a && tempB > 0) { // 防止溢位
        tempB <<= 1;
        power <<= 1;
    }

    while (power > 1) {
        tempB >>= 1;
        power >>= 1;
        if (a >= tempB) {
            a = subtract(a, tempB); // 使用上面的減法函數
            result = add(result, power); // 使用上面的加法函數
        }
    }
    return result;
}