#User function Template for python3


class Solution:
    #Function to return a list containing the intersection of two arrays.
    def printIntersection(self, a, b):
        i=j=0
        result=[]
        n,m=len(a),len(b)
        while(i<n and j<m):
            if(a[i]==b[j]):
                result.append(a[i])
                i+=1
                j+=1
                if i<n and a[i]==a[i-1]:
                    i+=1
                if j<m and b[j]==b[j-1]:
                    j+=1
            elif(a[i]<b[j]):
                i+=1
            else:
                j+=1
        return sorted(set(result)) if result else [-1]
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        ob = Solution()
        l = ob.printIntersection(arr1, arr2)
        print(*l)

# } Driver Code Ends
