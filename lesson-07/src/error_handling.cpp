#include <iostream>
#include <system_error>
#include <vector>

const std::string gLocalhost = "http://127.0.0.1/";

enum class HttpError
{
    Ok = 200,
    NotFound = 404
};

class HttpCategory: public std::error_category
{
public:
    const char* name() const noexcept override
    {
        return "http";
    }

    std::string message(int code) const override
    {
        switch(code)
        {
            case 200: return "ok";
            case 404: return "not found";
            default: return "unknown code";
        }
    }
};

std::error_code make_error_code(HttpError error)
{
    static const HttpCategory instance;
    return std::error_code(
        static_cast<int>(error),
        instance
    );
}

std::error_code download(const std::string& url)
{
    if (url == gLocalhost)
    {
        return make_error_code(HttpError::Ok); // std::error_code();
    }
    return make_error_code(HttpError::NotFound);
}

int main()
{
    const std::vector<std::string> urls = {"http://127.0.0.1/", "https://vk.com"};
    for (auto &url : urls)
    {
        auto error = download( url );
        //download( url );
        if (error)
        {
            std::cout << "ERROR: " << error.message() << std::endl;
        }
    }
}
