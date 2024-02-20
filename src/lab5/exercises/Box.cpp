#include <iostream>
#include <memory>

using namespace std;
class Box {
public:
    int side;

    Box(int side) {
        this->side = side;
    }
    ~Box() {
        cout << "Box object is being deleted" << endl;
    }



};
int create_unique(int size) {
    unique_ptr<Box> b = make_unique<Box>(size);
    return b->side;
}
void create_shared_boxes(int side) {
    shared_ptr<Box> boxPtr1 = make_shared<Box>(side);
    shared_ptr<Box> boxPtr2 = make_shared<Box>(side);

    cout << "Box 1 side: " << boxPtr1->side << ", use_count: " << boxPtr1.use_count() << endl;
    cout << "Box 2 side: " << boxPtr2->side << ", use_count: " << boxPtr2.use_count() << endl;

    shared_ptr<Box> boxPtr3 = boxPtr1;
    shared_ptr<Box> boxPtr4 = boxPtr2;

    cout << "After creating new shared_ptrs:" << endl;
    cout << "Box 1 side: " << boxPtr1->side << ", use_count: " << boxPtr1.use_count() << endl;
    cout << "Box 2 side: " << boxPtr2->side << ", use_count: " << boxPtr2.use_count() << endl;

}

void demonstrate_weak_ptr(int side) {
    shared_ptr<Box> boxPtr = make_shared<Box>(side);
    weak_ptr<Box> weakBoxPtr = boxPtr;

    if (weakBoxPtr.expired()) {
        cout << "Box object has been deleted." << endl;
    } else {
        cout << "Box object is still alive." << endl;
        shared_ptr<Box> sharedBoxPtr = weakBoxPtr.lock();
        cout << "Box side: " << sharedBoxPtr->side << endl;
    }
}

int main() {
    int side = create_unique(10);

    auto p1 = make_unique<Box>(10);
//    auto p2 = p1; - error
    create_shared_boxes(12);
    demonstrate_weak_ptr(15);
    return 0;

}