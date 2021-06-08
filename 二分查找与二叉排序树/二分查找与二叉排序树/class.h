#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int num):val(num),left(NULL),right(NULL){}
};
struct BSTNode {
	int val;
	int count;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int x) :val(x), count(0), left(NULL), right(NULL) {}
};

class solution {
public:
	//1.利用循环实现二分查找
	bool binary_search1(vector<int>& sort_array, int target);
	//2.利用递归实现二分查找
	bool binary_search2(vector<int>& sort_array, int begin, int end, int target);

	/*3.给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
		如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
		你可以假设数组中无重复元素。*/
	int searchInsert(vector<int>& nums, int target);

	/*4.给定一个按照升序排列的整数数组 nums，和一个目标值 target。
		找出给定目标值在数组中的开始位置和结束位置。
		如果数组中不存在目标值 target，返回 [-1, -1]。*/
	//4.1 寻找左端点
	int left_bound(vector<int>& nums, int target);
	//4.2 寻找右端点
	int right_bound(vector<int>& nums, int target);
	
	vector<int> searchRange(vector<int>& nums, int target);

	/*5.整数数组 nums 按升序排列，数组中的值 互不相同 。
		在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了旋转，
		使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
		例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
		给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，
		则返回它的下标，否则返回 -1 。*/
	int search(vector<int>& nums, int target);

	/*6.二叉查找树的插入实现*/
	void BST_insert(TreeNode* node, TreeNode* insert_node);

	/*7.二叉搜索树的搜索*/
	bool BST_search(TreeNode* node, int value);

	/*8.将字符串数字转换为数字。例如：str:"12345",int:12345*/
	int pow_int(int a, int b);
	int str_to_int(string& str);

	/*9 序列化和反序列化二叉搜索树*/
	/*9.1将数字转换为字符串#的形式，例如：int：1234 -> string:"1234#"*/
	void change_int_to_string(int val, string& str_val);
	/*9.2 将二叉查找树按照前序遍历的方式，转化为字符串，数字之间使用#隔开*/
	void BST_preorder(TreeNode* node, string& data);
	string serialize(TreeNode* root);
	TreeNode* deserialize(string data);

	/*10.给定一个整数数组 nums，按要求返回一个新数组 counts。
		 数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
		示例：
		输入：nums = [5,2,6,1]
		输出：[2,1,1,0] 
		解释：
		5 的右侧有 2 个更小的元素 (2 和 1)
		2 的右侧仅有 1 个更小的元素 (1)
		6 的右侧有 1 个更小的元素 (1)
		1 的右侧有 0 个更小的元素*/
	void BSTInsert(BSTNode* node, BSTNode* insert_node, int& count_small);
	vector<int> countSmaller(vector<int>& nums);
};
