### 开发环境：

64位 Win11系统， Visual Studio Community 2017， Qt 5.12.4（MSVC 2017 32-bit），Qt Creator 4.9.1， C++ 语言

### 抽象数据结构说明：

1. **字符串 CharString**
   	CharString类的成员变量 有： int 类型的 _len 和 capacity 分别表示当前长度和容量 ，以及wchar_t* 类型的 _str 存储字符数组 。该类的实现采用动态分配内存的方式，即：若当前容量不足时，重新申请分配一段两倍原长的内存，将字符串拷贝到新内存，并释放原内存。 这种实现方式保证了字符串的 操作 （在末尾连接字符串）的均摊复杂度是 O( m )为被合并的字符串的长度 ；而空间是 O(length) 的 。

   ​	CharString实现的成员函数 （运算符有：

   - 查询： lengthlength, capacitycapacity, emptyempty, indexOf (子串第一次出现的位置，使用 KMP算法）

   - 修改： clearclear, assign (operator=）, operator +=, reserve （扩充容量）

   - 索引： operator [ ], substring

     友元函数（运算符）有：

   - 连接： concat (operator +)

   - 输入输出： operator << , operator>>

2. **字符串链表 CharStringLink**

   ​	CharStringLink类采用双向链表的形式实现，链表的每个节点存有CharString 类型的数据。 该类在执行插入和删除等操作时动态申请（销毁） 对应节点的内存 。

   ​	CharStringLink类实现的成员函数（运算符）有：

   - 查询： e mptympty, search （查找某元素第一次出现的下标)
   - 修改 operator = , push_ back (add ), push_front front, removeremove, concat
   - 遍历： begin, end （返回迭代器类型，同时还实现了迭代器的operator ++ 和 operator *)还重载了友元运算符operator 用于输出。

3. **栈 Stack**

   ​	Stack是一个模板类，它的模板参数是 value_t ，表示元素的类型。它的成员变量有：int 类型的 _toptop, _capacity 分别表示栈顶的下标和当前容量，以及v alue_t* 类型的 stack存储栈中元素。
   ​	该模板类的实现也采用了动态分配内存的方式，即容量不足时重新分配一段两倍的内存。这样保证了栈的push 操作的均摊复杂度是 O(1) 的 ；而空间是O(size) 的。

   ​	Stack模板类实现的成员函数（ 运算符 ）有：

   - 查询： size, capacity, top, empty
   - 修改： operator =, push, pop, reserve

4. **向量 Vector**

   ​	Vector 是一个模板类，实现与 Stack 基本类似。它的模板参数是 value_t它的成员变量有： int类型的 _size, _capacity 和 value_t * 类型的vector 。
   ​	该模板类也采用动态分配内存的方式，保证了 push _back 的均摊复杂度是O(1) 的，而空间是 O(size) 的。

   ​	Vector模板类实现的成员函数（运算符）有：

   - 查询： size, capacity, back, front, empty
   - 修改： push_back, pop_back
   - 索引： operator [ ], at 

5. **哈希表 HashMap**

   ​	HashMap是一个模板类，它的模板参数是 key_t, value_t 分别表示键和值的类型，以及函数指针类型的 hash_t hashFunc(const key_t&)，表示 hash 函数。使用该类时需要保证每一个元素的键都是唯一的。 
   ​	该类采用链表的方式实现。成员变量 unsigned hashSize 是一个质数，作为hash 的模数，也就是 hash 表表头数组 List **head 的大小。List是链表节点的类型，它的成员有 key_t key，value_t value，List* next。当往 hash表中插入新元素时，将键的 hash 值对 hashSize 取模后，加入到对应链表的表头，查询时类似。 
   ​	该类采用动态分配内存的方式：当前的节点总数接近 hashSize时，重新分配两倍的内存。这样保证了在 hash 函数理想时，查询和索引的复杂度是期望 O(1)的，插入的复杂度是均摊 O(1) 的，空间复杂度是 O(size) 的。 

   ​	HashMap模板类实现的成员函数有：

   - 查询：size, find（是否给定的键是否存在）

   - 修改：reserve, insert

   - 索引：operator [ ]

6. **二叉平衡树 SplayTree**

   ​	SplayTree是一个模板类，模板参数 key_t, data_t 分别表示键和值的类型。

   ​	该模板类依据二叉平衡树的一种实现方式：伸展树（Splay Tree）算法实现，能够在 O(log 𝑛) 的时间复杂度完成二叉搜索树的插入、删除、查找操作。

   ​	SplayTree模板类实现的成员函数（运算符）有：

   - 修改：adjust（调整二叉树使其平衡）, insert, remove
   - 查询（索引）：search, find, at, operator [ ], list

7. **文档链表 DocumentList** 

   ​	DocumentList类的链表节点存储了文档相关的信息：序号 id 以及文档在链表中的排序依据rating。在进行添加、修改和删除等操作之后始终保持链表依据 rating 降序排列。在本次实验中，rating表示单词在文档中的出现次数。

   ​	DocumentList类实现的成员函数（运算符）有：

   - 修改：add, remove, edit（修改 id 对应的 rating，并维持有序）
   - 查询：search（查找给定 id对应的 rating）, empty
   - 遍历：begin, end（返回迭代器，还实现了迭代器类型的 operator++ 和 next等操作）

8. **倒排文档 InvertedIndex**

   ​	倒排文档由索引和文档链表组成，能够实现根据内容查询文档的快速操作。 InvertedIndex 是一个模板类，它的模板参数是索引数据结构类型 index_t。在本次实验中，index_t可取 SplayTree 或 HashMap。 
   ​	在InvertedIndex中index_t的data_t=TermInfo，这一结构存储了单词，单词id，单词出现文档数，单词出现总次数，以及对应的文档链表。 

   ​	InvertedIndex 模板类实现的成员函数有：

   - inc：在文档链表 word中找到文档 docId，并将出现次数加 1
   - add：在文档链表 word中插入文档 (docId, rating)
   - search：查找 word 对应的 TermInfo

### 算法说明

1、 Html 解析 
	HtmlParser类采用栈标签全遍历的形式解析 html 文档的结构。具体地，维护一个Stack<HtmlTag> 类型的栈。 
	HtmlTag是自定义的数据结构，它的成员：CharString _type 表示标签的类型（如 p, span, div等），Vector<TagAttribute> _attr 存储标签属性（TagAttribute类型本质上是一个 pair，有成员 CharString _key, _value）， CharString _content 存储标签中的文本内容。 

2、 电影检索 
	建立倒排文档：读取电影文件，解析信息，并将电影名和剧情简介分词（结果输出至数据库，以便下次直接读取）。依据分词结果，通过索引数据结构，将该文档快速加入逐个单词对应的文档链表中。 
	检索：首先将用户给定的关键词进一步分词，然后依次查询分词后的各个关键词的文档链表。合并以上链表后，将检索得到的电影根据出现的关键词个数为第一关键字，总出现次数为第二关键字进行排序并输出。