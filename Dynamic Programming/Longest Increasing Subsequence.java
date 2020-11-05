class LIS {
    public int search(int[] tail,int i,int r){
        int l = 0, m = 0,ans = -1;
        while(l<=r){
            m = l+(r-l)/2;
            if(tail[m]>=i){
                r = m-1;
                ans = m;
            }
            else
                l = m + 1;
            
        }
        return ans;
    }
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
        if(len == 0)
            return 0;
        int[] tail = new int[len];
        tail[0] = nums[0];
        int tailP = 0;
        for(int i=1;i<len;i++){
            if(nums[i]>tail[tailP]){
                tailP++;
                tail[tailP] = nums[i];
            }
            else{
                int k = search(tail,nums[i],tailP);
                tail[k] a= nums[i];
            }
        }
        return tailP+1;
    }
    public static void main(String[] args){
      int[] arr = {2,3,5,1,5,6,7};
      System.out.println(lengthOfLIS(arr));
    }
}
