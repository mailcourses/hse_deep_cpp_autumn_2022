#include <iostream>
#include <vector>
#include <map>

using map_t = std::map<std::string, std::vector< std::pair<size_t, size_t> > >;

template<typename Container, typename Index>
auto get_item(Container &c, Index i) -> decltype(c[i])
{
    return c[i];
}

template<typename A, typename B>
auto add(A a, B b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
    std::cout << add(10, 0.5) << std::endl;

    std::map<std::string, std::vector< std::pair<size_t, size_t> > > items;
    items["dogs"] = { std::make_pair(10, 5), std::make_pair(3, 1) };
    std::vector< std::pair<size_t, size_t> > dog_items = items["dogs"];
    auto dog_it = dog_items.begin();
    auto map_it = items.begin(); // std::map<std::string, std::vector< std::pair<size_t, size_t> > >::iterator
    map_t::iterator map_it_2 = items.begin();

    auto dog = get_item(dog_items, 0); // Container = std::vector< std::pair<size_t, size_t> >, Index = size_t.
    std::cout << "dog weight = " << dog.first << ", dog age = " << dog.second << std::endl;

    auto dogs = get_item(items, "dogs"); // Container = std::map<std::string, std::vector< std::pair<size_t, size_t> > >
    // Index = std::string.

    for (size_t i = 0; i < dog_items.size() ; ++i)
    {
        // dog_items[i]
    }

    for ( const std::pair<size_t, size_t> & elem : dog_items )
    {
    }

    for ( const auto & elem : dog_items )
    {
    }

    for ( const auto & elem : items )
    {
        std::cout << "Key=" << elem.first << std::endl;
    }
}
