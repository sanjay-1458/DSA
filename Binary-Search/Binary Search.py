def Binary_Search_R(nums:list[int],low:int,high:int,target:int) -> int:
    if low<=high:
        mid=int(low+(high-low)/2)
        if nums[mid]==target:
            return mid
        elif nums[mid]>target:
            return Binary_Search_R(nums,low,mid-1,target)
        else:
            return Binary_Search_R(nums,mid+1,high,target)
    return -1

def Binary_Search(nums:list[int],target:int) -> int:
    low = 0
    high=len(nums)-1
    while low<=high:
        mid=int(low+(high-low)/2)
        if nums[mid]==target:
            return mid
        elif nums[mid]>target:
            high=mid-1
        else:
            low=mid+1
    else:
        return -1

def main():
    size=10
    target=66
    nums=[1,3,5,7,9,11,22,44,66,77]
    print(Binary_Search(nums,target))
    print(Binary_Search_R(nums,0,len(nums)-1,target))

if __name__=="__main__":
    main()
