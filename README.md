# BinTreeView

Visualize binary tree in C/C++ language. Layout with `graphviz` and display with `OpenCV`.

## Tree Format

The binary tree must contain three public member variables: `val`, `left`, and `right`. Where the `val` is the node data variable, the `left` and the `right` are pointers to the binary tree itself. You could define binary tree as follow, which you could see in `./test/test.cpp`

```C++
struct BinTree
{
    int val;
    BinTree* left;
    BinTree* right;
    BinTree(int x): val(x),
                    left(NULL),
                    right(NULL){}
    ~BinTree(){
        if(left){
            delete left;
        }
        if(right){
            delete right;
        }
    }
};
```


## Usage

**Note:** It has only been tested on Ubuntu 18.04 and is not compatible with other platforms, and it can be modified on other platforms as needed.

```bash
git clone https://github.com/hefvcjm/BinTreeView.git
cd BinTreeView
mkdir build
cd build
camke ..
make

```

After complie the project, you could find the executable in the path `build/test/bin` and it should be named `bintree_view`. Execute it and see the result.

## Dependences

This project relies on two third-party libraries, `OpenCV` and `graphviz`, and this article uses `opencv 3.2.0` and `graphviz 2.40.1`.

## Example

Visualize binary tree without highlight nodes as follow:

![visualize without highlight nodes](https://github.com/hefvcjm/BinTreeView/raw/master/test/image/no_highlight.png)

And with highlight nodes as follow:

![visualize without highlight nodes](https://github.com/hefvcjm/BinTreeView/raw/master/test/image/highlight.png)

