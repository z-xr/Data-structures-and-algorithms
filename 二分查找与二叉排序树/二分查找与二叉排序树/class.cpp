#include<iostream>
#include<vector>
#include "class.h"
#include<string>
using namespace std;


//1.利用循环实现二分查找
bool solution::binary_search1(vector<int>& sort_array, int target) {
	int begin = 0;
	int end = sort_array.size() - 1;
	int mid = (begin + end) / 2;

	while (begin <= end) {
		if (target == sort_array[mid]) {
			return true;
		}
		else if (target < sort_array[mid]) {
			end = mid - 1;
			mid = (begin + end) / 2;
		}
		else if (target > sort_array[mid]) {
			begin = mid + 1;
			mid = (begin + end) / 2;
		}
	}
	return false;
}

//2.利用递归实现二分查找
bool solution::binary_search2(vector<int>& sort_array, int begin, int end, int target) {
	if (begin > end) {
		return false;
	}
	int mid = (begin + end) / 2;
	if (target == sort_array[mid]) {
		return true;
	}
	else if (target < sort_array[mid]) {
		binary_search2(sort_array, begin, mid - 1, target);
	}
	else if (target > sort_array[mid]) {
		binary_search2(sort_array, mid + 1, end, target);
	}
}

/*3.给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
		如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
		你可以假设数组中无重复元素。leetcode(35)*/
int solution::searchInsert(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;
	int index = -1;

	while (index == -1) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			index = mid;
		}
		else if (target < nums[mid]) {
			if (mid == 0 || target > nums[mid - 1]) {
				index = mid;
			}
			end = mid - 1;
		}
		else if (target > nums[mid]) {
			if (mid == nums.size() - 1 || target < nums[mid + 1]) {
				index = mid + 1;
			}
			begin = mid + 1;
		}
	}
	return index;
}

/*4.给定一个按照升序排列的整数数组 nums，和一个目标值 target。
		找出给定目标值在数组中的开始位置和结束位置。
		如果数组中不存在目标值 target，返回 [-1, -1]。*/

int solution::left_bound(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;

	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			if (mid == 0 || target > nums[mid - 1]) {
				return mid;
			}
			end = mid - 1;
		}
		else if (target < nums[mid]) {
			end = mid - 1;
		}
		else if (target > nums[mid]) {
			begin = mid + 1;
		}
	}
	return -1;

}
int solution::right_bound(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;

	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			if (mid == nums.size() - 1 || target < nums[mid + 1]) {
				return mid;
			}
			begin = mid + 1;
		}
		else if (target < nums[mid]) {
			end = mid - 1;
		}
		else if (target > nums[mid]) {
			begin = mid + 1;
		}
	}
	return -1;

}
vector<int> solution::searchRange(vector<int>& nums, int target) {
	int left = left_bound(nums, target);
	int right = right_bound(nums, target);

	vector<int> result;
	result.push_back(left);
	result.push_back(right);
	return result;
}


//5.旋转数组查找
int solution::search(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;

	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			return mid;
		}
		else if (target < nums[mid]) {
			if (nums[begin] < nums[mid]) {
				if (target >= nums[begin]) {
					end = mid - 1;
				}
				else {
					begin = mid + 1;
				}
			}
			else if (nums[begin] > nums[mid]) {
				end = mid - 1;
			}
			else if (nums[begin] == nums[mid]) {
				begin = mid + 1;
			}
		}
		else if (target > nums[mid]) {
			if (nums[begin] < nums[mid]) {
				begin = mid + 1;
			}
			else if (nums[begin] > nums[mid]) {
				if (target >= nums[begin]) {
					end = mid - 1;
				}
				else {
					begin = mid + 1;
				}
			}
			else if (nums[begin] == nums[mid]) {
				begin = mid + 1;
			}
		}
	}
	return -1;
}


/*6.二叉查找树的插入实现*/
void solution::BST_insert(TreeNode* node, TreeNode* insert_node) {
	if (insert_node->val < node->val) {
		if (node->left) {
			BST_insert(node->left, insert_node);
		}
		else {
			node->left = insert_node;
		}
	}
	else {
		if (node->right) {
			BST_insert(node->right, insert_node);
		}
		else {
			node->right = insert_node;
		}
	}
}

/*7.二叉搜索树的搜索*/
bool solution::BST_search(TreeNode* node, int value) {
	if (value == node->val) {
		return true;
	}
	else if (value < node->val) {
		if (node->left) {
			BST_search(node->left, value);
		}
		else {
			return false;
		}
	}
	else if (value > node->val) {
		if (node->right) {
			BST_search(node->right, value);
		}
		else {
			return false;
		}
	}
}

/*8.将字符串数字转换为数字。例如：str:"12345",int:12345*/
int solution::pow_int(int a, int b) {
	int sum = 1;
	for (int i = 0; i < b; i++) {
		sum = sum*a;
	}
	return sum;
}
int solution::str_to_int(string& str) {
	int length = str.size();
	vector<int> array;
	int sum = 0;
	for (int i = 0; i < length; i++) {
		array.push_back(str[i]-'0');
	}
	for (int i = length - 1,j=0; i >= 0; i--,j++) {
		sum = sum + array[i] * pow_int(10,j);
	}
	return sum;
}

/*9 序列化和反序列化二叉搜索树*/
	/*9.1将数字转换为字符串#的形式，例如：int：1234 -> string:"1234#"*/
void solution::change_int_to_string(int val, string& str_val) {
	string tmp;
	while (val) {
		tmp += val % 10 + '0';
		val = val / 10;
	}
	for (int i = tmp.length()- 1; i >= 0; i--) {
		str_val += tmp[i];
	}
	str_val += '#';
}
	/*9.2 将二叉查找树按照前序遍历的方式，转化为字符串，数字之间使用#隔开*/
void solution::BST_preorder(TreeNode* node, string& data) {
	if (!node) {
		return;
	}
	string str_val;
	change_int_to_string(node->val, str_val);
	data += str_val;
	BST_preorder(node->left, data);
	BST_preorder(node->right, data);
}

// Encodes a tree to a single string.
string solution::serialize(TreeNode* root) {
	string data;
	BST_preorder(root, data);
	return data;
}

// Decodes your encoded data to tree.
TreeNode* solution::deserialize(string data) {
	int val = 0;
	vector<TreeNode*> node_vec;

	if (data.length() == 0) {
		return NULL;
	}

	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '#') {
			node_vec.push_back(new TreeNode(val));
			val = 0;
		}
		else {
			val = val * 10 + (data[i] - '0');
		}
	}

	for (int i = 1; i < node_vec.size(); i++) {
		BST_insert(node_vec[0], node_vec[i]);
	}
	return node_vec[0];
}



/*10.给定一个整数数组 nums，按要求返回一个新数组 counts。
     数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。*/
void solution::BSTInsert(BSTNode* node, BSTNode* insert_node, int& count_small) {
	if (insert_node->val <= node->val) {
		node->count++;
		if (node->left) {
			BSTInsert(node->left, insert_node, count_small);
		}
		else {
			node->left = insert_node;
		}
	}
	else {
		count_small += node->count + 1;
		if (node->right) {
			BSTInsert(node->right, insert_node, count_small);
		}
		else {
			node->right = insert_node;
		}
	}
}

vector<int> solution::countSmaller(vector<int>& nums) {
	vector<int> result;
	vector<int> count;
	vector<BSTNode*> node_vec;

	for (int i = nums.size() - 1; i >= 0; i--) {
		node_vec.push_back(new BSTNode(nums[i]));
	}

	count.push_back(0);
	for (int i = 1; i < node_vec.size(); i++) {
		int count_small = 0;
		BSTInsert(node_vec[0], node_vec[i], count_small);
		count.push_back(count_small);
	}

	for (int i = node_vec.size() - 1; i >= 0; i--) {
		delete node_vec[i];
		result.push_back(count[i]);
	}
	return result;
}