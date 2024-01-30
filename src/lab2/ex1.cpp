class Box {
private:
    unsigned int length;
    unsigned int width;
    unsigned int height;
public:
    Box(){
        length = 1;
        width = 1;
        height = 1;
    }
    Box(unsigned int a){
        length = a;
        width = a;
        height = a;
    }
    Box(Box& b){
        length = b.length;
        width = b.width;
        height = b.height;
    }
    Box(unsigned int a, unsigned int b, unsigned int c){
        length = a;
        width = b;
        height = c;
    }
    void operator=(int v){
        length = v;
    }
    unsigned getVolume(){
        return length*width*height;
    }
    void scale(unsigned scaleValue) {
        length = length*scaleValue;
        height = height*scaleValue;
        width = width*scaleValue;
    }
    bool isBigger(Box& other) {
        return (this->getVolume() > other.getVolume());
    }
    bool isSmaller(Box& other) {
        return !isBigger(other);
    }
    void operator*(int v){
        new Box(this->length*v, this->width*v, this->height*v);
    }
    bool operator==(Box& other){
        return (this->length == other.length || this->length == other.width ||this->length == other.height ||
        this->height == other.length || this->height == other.width ||this->height == other.height ||
        this->width == other.length || this->width == other.width ||this->width == other.height);
    }
};

class Cube {
    unsigned int side;
    Cube(unsigned int a) {
        side = a;
    }
    void operator->() {
        new Box(side);
    }
};