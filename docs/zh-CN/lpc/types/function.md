## 一般概念

> MudOS 有一种称为 `function`  (函数指针) 的变量型态. 这种型态的变量可以用来指向各种不同的函数. 您也许早已熟悉把一个函数当作某些外部函数 (efuns) 参数. 举例来说, 像是过滤阵列的外部函数. 它读入一个阵列, 并经由一个函数过滤阵列中的元素. 让此函数传回非零值 (non-zero) 的元素就保留下来, 结果传回一个新的阵列. 传统上, 这样做要传入一个对象和函数的名称. 现在, 可以用函数指标这种变量型态做到. 函数指针只含有一个函数的资讯, 可以在稍后执行其函数.
----------
函数指针可以创造并指定为变量:
```lpc
function f = (: local_func :);
```
上面的 f  可以用于其他方法流程或外部函数中, 如同普通的变量值:
```c
foo(f);
map_array( ({ 1, 2 }), f);
```
或是稍后再执行 f:
```c
x = evaluate(f, "hi");
```
上一行执行时, 会呼叫 f  指向的函数, 而 "hi" 当成参数传入函数. 其效果同下:
```c
x = local_func("hi");
```
使用函数指针的好处是, 如果您想使用不同的函数, 只需要改变函数指针变量的值.

注意 evaluate() 的参数如果不是函数, 就只会传回参数值. 所以您可以做以下的
事:
```c
void set_short(mixed x)
{
    short = x;
}

mixed query_short()
{
    return evaluate(short);
}
```
这样, 简单的对象可以只用 set_short("Whatever"); 以达成
set_short( (: short_func :) ); 的效果.


## 目前函数指针的种类

最简单的函数指针如上面所述. 只是简单地指向同一个对象中的一个区域函数(local function), 即 (: function_name :). 函数指针的值可以包括函数的参数,例如:
```c
string foo( string a, string b ) {
   return "(" + a "," + b + ")";
}

void create() {
    function f = (: foo, "left" :);

    printf( "%s %s\n", evaluate(f), evaluate(f, "right") );
}
```
会输出:
>(left,0) (left,right)


第二种的函数指针是外部函数指针, 就是 (: efun_name :). 这样与区域函数指针很类似. 譬如说, objects() 外部函数要传入函数, 并传回任何使函数为真值的对象. 所以:
```c
objects( (: clonep :) )
```
会传回游戏中所有的复制对象 (clones). 您也可以使用参数:
```c
void create() {
    int i;
    function f = (: write, "Hello, world!\n" :);

    for (i=0; i<3; i++) { evaluate(f); }
}
```
就会输出:
> Hello, world!

> Hello, world!

> Hello, world!

注意, 对函数指针来说, simul_efuns  (模拟外部函数) 与外部函数是相同的.


第三种形式是 call_other 函数指针, 与以前 MudOS  所使用的函数指针型态类似.其形式为 (: object, function :).  要使用参数的话, 应将函数名称与参数的阵列并用. 以下是范例:
```c
void create()
{
     string *ret;
     function f = (: this_player(), "query" :);

     ret = map( ({ "name", "short", "long" }), f );
     write(implode(ret, "\n"));
}
```
这样会输出与 this_player()->query("name")、this_player()->query("short")、this_player()->query("long") 相同的结果.

要使一个函数指针直接呼叫 query("short") :
```c
f = (: this_player(), ({ "query", "short" }) :)
```
以下是达到同样目的的做法参考:
```c
// 一个外部函数指针,使用 call_other
f = (: call_other, this_player(), "query", "short" :)
// 等效的运算式请见下文
f = (: this_player()->query("short") :)
```

第四种形式是运算式 (expression) 函数指针. 就是 (: 运算式 :).  在一个运算式函数指针中, 参数可以用 $1, $2, $3 ... 代表, 举例如下:
```c
evaluate( (: $1 + $2 :), 3, 4)  // 传回 7.
```
这可以用于 sort_array, 范例如下:
```c
top_ten = sort_array( player_list, (: $2->query_level() - $1->query_level :) )[0..9];
```

第五种形式是不知名 (anonymous)  函数:
```c
void create() {
    function f = function(int x) {
        int y;

        switch(x) {
        case 1: y = 3;
        case 2: y = 5;
        }
        return y - 2;
    };

    printf("%i %i %i\n", (*f)(1), (*f)(2), (*f)(3));
}
```
会输出:
> 1 3 -2

注意, (*f)(...) 等于 evaluate(f, ...) , 保留这种语法是为了与旧版相容.任何普通函数合法 (legal)  的写法, 都可以用于不知名函数.

### 什么时候执行 (evaluate) 函数 ?

创造带有参数的外部函数、区域函数、模拟外部函数指针时, 会执行函数. 而运算式和功能性 (functional) 函数指针, 只有在使用函数指针时执行函数:
```c
// 创造这个函数指针时, 就会摧毁 this_player(),函数于创造时执行.
(: destruct, this_player() :)
// 在稍后使用此函数指针时, 才会摧毁 this_player()
(: destruct(this_player()) :)
```
在此, 不可以在运算式函数指针里, 使用一个区域变量. 因为执行这个函数指针之后, 这个区域变量就不存在了. 但是可以用下面这个方法解决:
```c
(: destruct( $(this_player) ) :) // 与上面第一个示例相同.
```
$(whatever) 表示要执行 whatever, 并保留其值. 当执行此函数时, 再传入这个值.这样一来可以更有效率:
```c
map_array(listeners, (: tell_object($1, $(this_player()->query_name()) + " bows.\n") :) );
```
只做一次 call_other , 而不需要每个讯息都做. 也可以事先合并字串:
```c
map_array(listeners, (: tell_object($1, $(this_player()->query_name() + " bows.\n")) :) );
```
注意, 在这个情形下, 也可以这样做:
```
map_array(listeners, (: tell_object, this_player()->query_name() + " bows.\n" :) );
```
