struct Query{
    int l, r, index;
};

int K; // = sqrt(N)
int a = 1, b = 0;

bool isLess(Query a, Query b){
    if(a.l / K != b.l / K){
        return a.l < b.l;
    }
    return a.r < b.r;
}


// function process(Query[Q] q):
//   sort(q, isLess) // сортируем запросы, используя функцию isLess как оператор сравнения
//   for i = 0 to Q - 1:
//     while a > q[i].l:
//       addLeft(a - 1)
//       a -= 1
//     while b < q[i].r:
//       addRight(b + 1)
//       b += 1
//     while a < q[i].l:
//       delLeft(a)
//       a += 1
//     while b > q[i].r:
//       delRight(b)
//       b -= 1
//     result[q[i].id] = answer() // получаем ответ на [a...b]  