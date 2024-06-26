#include <ext/pb_ds/assoc_container.hpp> // Общий файл. 
#include <ext/pb_ds/tree_policy.hpp> // Содержит класс tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// ИЛИ 
typedef tree<pair<int, int> , null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



ordered_set X;
X.insert(1);
X.insert(2);
X.insert(4);
X.insert(8);
X.insert(16);

cout<<*X.find_by_order(1)<<endl; // 2
cout<<*X.find_by_order(2)<<endl; // 4
cout<<*X.find_by_order(4)<<endl; // 16
cout<<(end(X)==X.find_by_order(6))<<endl; // true

cout<<X.order_of_key(-5)<<endl;  // 0
cout<<X.order_of_key(1)<<endl;   // 0
cout<<X.order_of_key(3)<<endl;   // 2
cout<<X.order_of_key(4)<<endl;   // 2
cout<<X.order_of_key(400)<<endl; // 5

// MULTISET :

// ERASE
int ind = s.order_of_key(X);
s.erase(s.find_by_order(ind));

// LOWER_BOUND EQ TO
Y = s.order_of_key(a);
// UPPER_BOUND EQ TO
X = s.order_of_key(b+1);