int game(int* guess, int guessSize, int* answer, int answerSize){
    int ans = 0;
    for (int i = 0; i < guessSize; i++) {
        guess[i] == answer[i] ? ans++ : 0;
    }
    return ans;
}