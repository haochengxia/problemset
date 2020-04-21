# Week 1

Date: 2020/4/13 - 202/4/19

## Review points:

1. Vector 
2. Stack
3. Struct and Class



## Vector 

`push_back()`

* detail in [Doc](http://www.cplusplus.com/reference/vector/vector/?kw=vector)



## Stack

`pop` `push` `top`

* detail in [Doc](http://www.cplusplus.com/reference/stack/stack/?kw=stack)



## Struct and Class

### Struct

```
c:	  struct  struct_type_name struct_variable_name
c++: (struct) struct_type_name struct_variable_name
```

declaration and define variable:

```
struct struct_type_name {
	member
} struct_variable_name_list;
```

define variable directly:

```
struct {
	member
} struct_variable_name_list;
```

add constructor

```
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main(){
	ListNode mNode(0);
	ListNode* nodePtr = new ListNode(1);
}
```



:star: The different between class and constructor. 

* When the access privilege is not defined, 

  **class**: default **private**; 

  **struct**: default **public**.

* Inheritance from class is private by default, while inheritance from struct is public by default.

 

