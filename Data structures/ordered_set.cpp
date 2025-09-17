#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Note on using less_equal as comparison function to use it as a multiset:
//1. _GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
//2. find will always return end.
//3. lower_bound works like upper_bound in normal set (to return the first element > it)
//4. upper_bound works like lower_bound in normal set (to return the first element >= it)
//5. find_by_order and order_of_key works properly (unlike the 2 functions above).