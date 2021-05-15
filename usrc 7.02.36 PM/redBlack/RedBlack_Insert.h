/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2020. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi<T> RedBlack<T>::insert ( const T& e ) { //将e插入红黑树
   BinNodePosi<T> & x = search ( e ); if ( x ) return x; //确认目标不存在（this->_hothot的设置）
   x = new BinNode<T> ( e, this->_hot, NULL, NULL, 0 ); this->_size++; //创建红节点this->_hothot为父，黑高度0
   BinNodePosi<T> xOld = x; solveDoubleRed ( x ); return xOld; //经双红修正后，即可返回
} //无论e是否存在于原树中，返回时总有x->data == e