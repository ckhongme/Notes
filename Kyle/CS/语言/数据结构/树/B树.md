一种平衡的多路查找树，它可以高效地支持大量数据的动态插入、删除和查找操作。与二叉查找树不同，B树每个节点可以包含多个关键字和指向子节点的指针；

B树有一个最小度数，通常用t来表示，每个节点至少包含t-1个关键字和t个子节点。根节点可以是任何度数，但是在B树中通常将根节点的度数保持在2到t之间。B树的高度通常非常小，因此可以在O(log n)时间内完成大多数的操作。

B树的一个重要特点是它能够支持高效的磁盘访问。在数据库系统等应用中，磁盘访问是非常昂贵的操作。B树通过将每个节点的大小限制在一个固定的范围内，从而使得一个节点可以完全存储在磁盘块中。这样，在查找某个关键字的过程中，可以仅仅读取包含目标关键字的那些磁盘块，而不必读取整棵树。

B树是数据库和文件系统等许多领域中广泛使用的数据结构之一，例如在Oracle、MySQL和PostgreSQL等数据库系统中都有应用。