#TAD-List

##What is this?

A 3 type of list implementation: Vector, Simple Liked List and Double Linked List

Every implementation have a group of basic methods for each implementation, some exclusives depending of the list type.

## How it works
Each source file, will run a series of unity test for each function and in diferent situations

##How to compile
In each list folder you'll have to use the following code on the terminal:

```shell
make clean
make
```

##How to run

###In the Vector folder:
```shell
./bin/vector
```
###In the Forward_list folder:
```shell
./bin/forward_list
```
###In the List folder:
```shell
./bin/vector
```

##Non implemented methods

```cpp
insert(iterator _it, const T &_x)

insert(iterator _it, InItr _ini, InItr _end)

insert(const_iterator _it, std::initializer_list<T> _il)

assign(InItr _ini, InItr _end)

insert_after ( const_iterator itr , const T & x );

insert_after ( const_iterator pos , std :: initializer_list <T > ilist );

const_iterator find (  const T &x ) const ;
```


## Author
 - Johnnylee Bryan Marques da Rocha - Github -> https://github.com/kfjohnny2