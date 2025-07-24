def find_kth_character(initial_string, K):
    n = len(initial_string)
    
    # Tìm độ dài xâu sau các lần mở rộng
    while K > n:
        n *= 2
    
    # Truy tìm vị trí ký tự thứ K
    while K > len(initial_string):
        if K > n // 2:
            K -= (n // 2)
            if K == 1:
                K = n // 2
            else:
                K -= 1
        
        n //= 2
    
    return initial_string[K - 1]

# Ví dụ sử dụng
K=int(input())
initial_string = input()
print(find_kth_character(initial_string, K))  # Output sẽ là 'b'
