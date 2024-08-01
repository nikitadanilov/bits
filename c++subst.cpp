
template <int N> __attribute__((optimize("align-functions=4096"))) int add(int m) {
    return N + m;
}

int (*add0)(int) = &add<0>;
int (*add2)(int) = &add<2>;
int (*sub1)(int) = &add<-1>;

static int (*arr[33])(int) = {};

template <int nr>
constexpr void init() {
    arr[nr] = add<nr>;
    init<nr - 1>();
}

template <>
constexpr void init<-1>() {
}

int main(int argc, char **argv) {
    init<32>();
    return arr[argc](argc);
}
