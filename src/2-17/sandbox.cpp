#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

const int insert = 101;

void result_print(int i)
{
    cout << i << " ";
}

auto print_array = [](auto input) -> void {
    array<int, 0>::iterator it = input.begin();
    for_each(it, input.end() - 1, result_print);
};

auto print_set = [](set<int> input) -> void {
    set<int>::iterator it = input.begin();
    for_each(it, input.end(), result_print);
};

vector<int> vec;
array<int, 5> arr1 = {insert, insert, 40, 30};
set<int> set1(arr1.begin(), arr1.end() - 1);

int main()
{
    bool mode = true;
    string text;
    auto helloworld = [](void) -> void {
        cout << "this call is from lambda exp." << endl;
    };

    for_each(&arr1[0], arr1.end() - 1, [](int i) -> void {
        vec.push_back(i);
    });

    text = mode ? "true" : "false";
    cout << "bool: " << text << endl;
    cout << "type of mode: " << typeid(mode).name() << endl << "input text: ";

    cin >> text;
    cout << text << " has " << text.size() << " letters" << endl;

    cout << "array: ";
    print_array(arr1);

    cout << endl << "vector :";
    for_each(vec.begin(), vec.end(), [](int i) -> void {
        cout << i << " ";
    });

    cout << endl << "set: ";
    print_set(set1);
    cout << endl;
    helloworld();
}