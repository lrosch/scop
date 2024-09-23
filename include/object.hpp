struct v3 
{
    float x;
    float y;
    float z;
};

struct face
{
    int a;
    int b;
    int c;
    int d;
    bool fourth_val = false;
    std::string material;
};

class Object{
    public:
        std::string object_file;
        std::vector<v3> vertices;
        std::vector<face> indices;
        bool smooth_shading;
        std::string name;

        Object();
        Object(std::string file);
        ~Object();
        int fill_in_from_object_file();
};