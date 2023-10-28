class Solution:
    def countBits(self, n: int) -> List[int]:
        arr=[]
        count=0
        for i in range(0, n + 1):
            for j in range(0,32):
                if(i&1==1):
                    count+=1
                i >>= 1
            arr.append(count)
            count=0
        return arr