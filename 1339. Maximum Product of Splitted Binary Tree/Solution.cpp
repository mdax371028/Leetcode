class Solution {
  public:
      int maxProduct(TreeNode* root) {
          long iMod = 1e9 + 7;
          set<long> SetNodeSum;

          if (root == nullptr)
              return 0;

          Postfix(SetNodeSum, root);

          long iTotal = *SetNodeSum.rbegin();
          long iHalf = iTotal / 2;

          set<long>::iterator it_Upper = SetNodeSum.lower_bound(iHalf);

          long iProduct = 0;
          if (it_Upper != SetNodeSum.end())
          {
              long iCmpProduct = (*it_Upper) * (iTotal - *it_Upper);
              iProduct = max(iProduct, iCmpProduct);
          }

          if (it_Upper != SetNodeSum.begin())
          {
              it_Upper--;
              long iCmpProduct = (*it_Upper) * (iTotal - *it_Upper);
              iProduct = max(iProduct, iCmpProduct);
          }

          return iProduct % iMod;
      }

      long int Postfix(set<long>& SetNodeSum, TreeNode* root)
      {
          if (root == nullptr)
              return 0;
          long iRight = Postfix(SetNodeSum, root->right);
          long iLeft = Postfix(SetNodeSum, root->left);
          SetNodeSum.insert(root->val + iLeft + iRight);

          return root->val + iLeft + iRight;
      }
  };
