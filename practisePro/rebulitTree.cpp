#include "solution.h"

BinaryTreeNode* builtTree(int* staPre, int* endPre, int* staIn, int* endIn){
    int value = *staPre;
    BinaryTreeNode* root = new BinaryTreeNode(value);

    if(staPre == endPre){
        if(staIn == endIn && *staIn == *staPre){
            return root;
        }else{
            logic_error ex("invlid input.");
            throw exception(ex);
        }
    }

    int* rootIn = staIn;
    while(rootIn != endIn && *rootIn != value){
        ++rootIn;
    }
    if(rootIn == endIn && *rootIn !=value){
        logic_error ex("invlid input.");
        throw exception(ex);
    }
    int leftLength = rootIn - staIn;
    if(leftLength > 0){
        root->left = builtTree(staPre, staPre + leftLength, staIn, staIn + leftLength - 1);
    }
    if(leftLength < endIn - staIn){
        root->right = builtTree(staPre + leftLength + 1, endPre, rootIn + 1, endIn);
    }
    return root;
}

BinaryTreeNode* solution::rebulitTree(int* preorder, int* inorder, int length)
{
    if(preorder == NULL || inorder == NULL || length <= 0){
        return NULL;
    }

    return builtTree(preorder, preorder + length - 1, inorder, inorder + length - 1);

}
