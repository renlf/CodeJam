auto cmp = [](std::pair<K,V> const & a, std::pair<K,V> const & b) 
{ 
     return a.second != b.second?  a.second < b.second : a.first < b.first;
};
std::sort(items.begin(), items.end(), cmp);
