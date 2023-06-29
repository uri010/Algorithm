#include <iostream>

using namespace std;

int cnt = 0; //총 수행 시간을 저장하는 변수

void swap(int *a, int *b) { //a와 b값을 바꾸고 바꾼 횟수(cnt)를 +1
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cnt++;
}

int getHeight(int cur, int N) { //cur의 height를 구하는 함수
    int h = 0;
    for (int i = cur * 2; i <= N; i = i * 2)
        h++;
    return h;
}

void bubbleUpHeap(int *arr, int root, int K, int vacant) { //K가 vacant의 부모보다 작아질 때까지 올라감
    if (vacant == root)
        arr[vacant] = K;
    else {
        int parent = vacant / 2;
        if (K <= arr[parent]) {
            arr[vacant] = K;
        } else {
            swap(&arr[vacant], &arr[parent]);
            bubbleUpHeap(arr, root, K, parent);
        }
    }
}

int promote(int *arr, int hStop, int vacant, int h) { // vacant의 height를 /2 해주는 함수
    int vacStop;
    int left = vacant * 2;
    int right = vacant * 2 + 1;

    if (h <= hStop)
        vacStop = vacant;
    //두 자식 중 큰 자식과 swap하고 promote 재귀 호출
    else if (arr[left] < arr[right]) {
        swap(&arr[vacant], &arr[right]);
        vacStop = promote(arr, hStop, right, h - 1);
    } else {
        swap(&arr[vacant], &arr[left]);
        vacStop = promote(arr, hStop, left, h - 1);
    }
    return vacStop;
}

void fixHeapFast(int *arr, int N, int K, int vacant, int h) {
    if (h == 0) return; //root일 때는 그냥 return
    if (h == 1) { //h가 1일 때는 두 자식 중 큰 자식이 자신보다 크면 swap
        int left = vacant * 2;
        int right = vacant * 2 + 1;

        if (arr[left] >= arr[right]) {
            if (arr[left] > arr[vacant]) {
                swap(&arr[vacant], &arr[left]);
            }
        } else {
            if (arr[right] > arr[vacant]) {
                swap(&arr[vacant], &arr[right]);
            }
        }
    } else {
        int hStop = h / 2;
        int vacStop = promote(arr, hStop, vacant, h); // vacant의 위치를 h/2로 옮겨줌
        int vacParent = vacStop / 2;

        if (arr[vacParent] <= K) { // 올라오는 경우
            swap(&arr[vacStop], &arr[vacParent]);
            bubbleUpHeap(arr, vacant, K, vacParent);
        } else {
            fixHeapFast(arr, N, K, vacStop, hStop);
        }
    }
}

void deleteMax(int *arr, int N) {
    //첫번째 원소에 마지막 원소를 넣어주고, 마지막 원소는 -1로 초기화
    arr[1] = arr[N];
    arr[N] = -1;
    cnt++;

    int h = getHeight(1, N - 1); //첫번째 원소와 N-1번째 원소의 높이 차이를 계산
    fixHeapFast(arr, N - 1, arr[1], 1, h);
}

void constructHeap(int *arr, int root, int N) {
    int left = root * 2;
    int right = root * 2 + 1;

    if (left > N) return;
    if (left <= N)
        constructHeap(arr, left, N);
    if (right <= N)
        constructHeap(arr, right, N);

    int h = getHeight(root, N); //root와 N의 높이 차이를 계산
    fixHeapFast(arr, N, arr[root], root, h);
}

void acceleratedHeapSort(int *arr, int N) { // 정렬 수행
    int n = N;
    int * sorted_arr = new int[N+1];
    for (int i = N; i > 1; i--) {
        int maxNum = arr[1];
        deleteMax(arr, n);
        n--;
        sorted_arr[i] = maxNum;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int *arr = new int[2 * N + 1];
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        constructHeap(arr, 1, N);

        cnt = 0;
        for (int i = 1; i <= N; i++)
            cout << arr[i] << " ";
        cout << "\n";

        acceleratedHeapSort(arr, N);

        cout << cnt << "\n";
    }
}