namespace mystd
{

template<typename T>
vector<T>::vector(size_t size) : size_(size), capacity_(size)
{
    std::cout << "vector<T>" << std::endl;
    if (size_)
    {
        data_ = new T[size_];
    }
}

template<typename T>
vector<T>::~vector()
{
    if (data_)
    {
        delete[] data_;
    }
}

/*
template class vector<int32_t>;
template class vector<std::string>;
*/

} // namespace mystd
