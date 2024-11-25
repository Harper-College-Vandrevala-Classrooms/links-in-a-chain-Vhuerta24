#include <iostream>
#include <string>
using namespace std;


class ChainLink {
private:
    string color;

public:
    ChainLink(string color) : color(color) {}

    string get_color() {
        return this->color;
    }
};


class Node {
private:
    ChainLink* data;
    Node* next;

public:
    // Constructor with optional next node parameter
    Node(ChainLink* chainLink, Node* nextNode = nullptr)
        : data(chainLink), next(nextNode) {}

    // Getter for data
    ChainLink* get_data() {
        return data;
    }

    // Getter for next node
    Node* get_next() {
        return next;
    }
};

int main() {
    // Create ChainLink objects
    ChainLink link_one("red");
    ChainLink link_two("blue");
    ChainLink link_three("green");

    // Create Node objects with chaining
    Node node_three(&link_three);
    Node node_two(&link_two, &node_three);
    Node node_one(&link_one, &node_two);

    // Tests the retrieval of links
    Node* retrieved_node = node_one.get_next(); // Second node
    ChainLink* retrieved_link = retrieved_node->get_data();
    cout << "Second ChainLink color: " << retrieved_link->get_color() << endl;

    Node* another_retrieved_node = node_one.get_next()->get_next(); // Third node
    ChainLink* another_retrieved_link = another_retrieved_node->get_data();
    cout << "Third ChainLink color: " << another_retrieved_link->get_color() << endl;

    return 0;
}
