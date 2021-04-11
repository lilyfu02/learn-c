/**
 * CSC A48 - Intro to Computer Science II, Summer 2020
 * 
 * Assignment 3 - Graffit
 * 
 * Graphs &
 * Recursion
 * Assignment
 * For
 * Freshmen
 * In
 * Toronto
 *
 * (I am so proud of that initialism.)
 * 
 * This is the program file where you will implement your solution for
 * assignment 3. Please make sure you read through this file carefully
 * and that you understand what is provided and what you need to complete.
 * 
 * You will also need to have read the handout carefully. 
 * 
 * Parts where you have to implement functionality are clearly labeled TODO
 * 
 * Be sure to test your work thoroughly, our testing will be extensive
 * and will check that your solution is *correct*, not only that it
 * provides functionality.
 * 
 * (c) 2020 William Song, Mustafa Quraish
 **/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR_LEN 1024
#ifndef __testing
#define MAT_SIZE 3	// A small graph
#endif

typedef struct user_struct {
    char name[MAX_STR_LEN];
    struct friend_node_struct* friends;
    struct brand_node_struct* brands;
    bool visited;
} User;

typedef struct friend_node_struct {
    User* user;
    struct friend_node_struct* next;
} FriendNode;

typedef struct brand_node_struct {
    char brand_name[MAX_STR_LEN];
    struct brand_node_struct* next;
} BrandNode;

/** Note: We are reusing the FriendNode here as a Linked List for allUsers.
  * This is usually bad coding practice but it will allow us to reuse the
  * helper functions.
  **/
FriendNode* allUsers; 

int brand_adjacency_matrix[MAT_SIZE][MAT_SIZE];
char brand_names[MAT_SIZE][MAX_STR_LEN];

/**
 * Checks if a user is inside a FriendNode LL.
 **/
bool in_friend_list(FriendNode *head, User *node) {
  for (FriendNode *cur = head; cur != NULL; cur = cur->next) {
    if (strcmp(cur->user->name, node->name) == 0) {
      return true;
    }
  }
  return false;
}

/**
 * Checks if a brand is inside a BrandNode LL.
 **/
bool in_brand_list(BrandNode *head, char *name) {
  for (BrandNode *cur = head; cur != NULL; cur = cur->next) {
    if (strcmp(cur->brand_name, name) == 0) {
      return true;
    }
  }
  return false;
}

/**
 * Inserts a User into a FriendNode LL in sorted position. If the user 
 * already exists, nothing is done. Returns the new head of the LL.
 **/
FriendNode *insert_into_friend_list(FriendNode *head, User *node) {
  if (node == NULL) return head;

  if (in_friend_list(head, node)) {
    printf("User already in list\n");
    return head;
  }
  FriendNode *fn = calloc(1, sizeof(FriendNode));
  fn->user = node;
  fn->next = NULL;

  if (head == NULL)
    return fn;
    
  if (strcmp(head->user->name, node->name) > 0) {
    fn->next = head;
    return fn;
  } 

  FriendNode *cur;
  for (cur = head; cur->next != NULL && strcmp(cur->next->user->name, node->name) < 0;
       cur = cur->next)
    ;
  fn->next = cur->next;
  cur->next = fn;
  return head;
}

/**
 * Inserts a brand into a BrandNode LL in sorted position. If the brand 
 * already exists, nothing is done. Returns the new head of the LL.
 **/
BrandNode *insert_into_brand_list(BrandNode *head, char *node) {
  if (node == NULL) return head;

  if (in_brand_list(head, node)) {
    printf("Brand already in list\n");
    return head;
  }
  BrandNode *fn = calloc(1, sizeof(BrandNode));
  strcpy(fn->brand_name, node);
  fn->next = NULL;

  if (head == NULL)
    return fn;
    
  if (strcmp(head->brand_name, node) > 0) {
    fn->next = head;
    return fn;
  } 

  BrandNode *cur;
  for (cur = head; cur->next != NULL && strcmp(cur->next->brand_name, node) < 0;
       cur = cur->next)
    ;
  fn->next = cur->next;
  cur->next = fn;
  return head;
}

/**
 * Deletes a User from FriendNode LL. If the user doesn't exist, nothing is 
 * done. Returns the new head of the LL.
 **/
FriendNode *delete_from_friend_list(FriendNode *head, User *node) {
  if (node == NULL) return head;

  if (!in_friend_list(head, node)) {
    printf("User not in list\n");
    return head;
  }

  if (strcmp(head->user->name, node->name) == 0) {
    FriendNode *temp = head->next;
    free(head);
    return temp;
  }

  FriendNode *cur;
  for (cur = head; cur->next->user != node; cur = cur->next)
    ;

  FriendNode *temp = cur->next;
  cur->next = temp->next;
  free(temp);
  return head;
}

/**
 * Deletes a brand from BrandNode LL. If the user doesn't exist, nothing is 
 * done. Returns the new head of the LL.
 **/
BrandNode *delete_from_brand_list(BrandNode *head, char *node) {
  if (node == NULL) return head;

  if (!in_brand_list(head, node)) {
    printf("Brand not in list\n");
    return head;
  }

  if (strcmp(head->brand_name, node) == 0) {
    BrandNode *temp = head->next;
    free(head);
    return temp;
  }

  BrandNode *cur;
  for (cur = head; strcmp(cur->next->brand_name, node) != 0; cur = cur->next)
    ;

  BrandNode *temp = cur->next;
  cur->next = temp->next;
  free(temp);
  return head;
}

/**
 * Prints out the user data.
 **/
void print_user_data(User *user) {
  printf("User name: %s\n", user->name);
  printf("Friends:\n");
  for (FriendNode *f = user->friends; f != NULL; f = f->next) {
    printf("   %s\n", f->user->name);
  }
  printf("Brands:\n");
  for (BrandNode *b = user->brands; b != NULL; b = b->next) {
    printf("   %s\n", b->brand_name);
  }
}

/**
 * Get the index into brand_names for the given brand name. If it doesn't
 * exist in the array, return -1
 **/
int get_brand_index(char *name) {
  for (int i = 0; i < MAT_SIZE; i++) {
    if (strcmp(brand_names[i], name) == 0) {
      return i;
    }
  }
  printf("brand '%s' not found\n", name);
  return -1; // Not found
}

/**
 * Print out brand name, index and similar brands.
 **/
void print_brand_data(char *brand_name) {
  int idx = get_brand_index(brand_name);
  if (idx < 0) {
    printf("Brand '%s' not in the list.\n", brand_name);
    return;
  }
  printf("Brand name: %s\n", brand_name);
  printf("Brand idx: %d\n", idx);
  printf("Similar brands:\n");
  for (int i = 0; i < MAT_SIZE; i++) {
    if (brand_adjacency_matrix[idx][i] == 1 && strcmp(brand_names[i], "") != 0) {
      printf("   %s\n", brand_names[i]);
    }
  }
}

/**
 * Read from a given file and populate a the brand list and brand matrix.
 **/
void populate_brand_matrix(char* file_name) {
    // Read the file
    char buff[MAX_STR_LEN];
    FILE* f = fopen(file_name, "r");
    fscanf(f, "%s", buff);
    char* line = buff;
    // Load up the brand_names matrix
    for (int i = 0; i < MAT_SIZE; i++) {
        if (i == MAT_SIZE - 1) {
            strcpy(brand_names[i], line);
            break;
        }
        int index = strchr(line, ',') - line;
        strncpy(brand_names[i], line, index);
        line = strchr(line, ',') + sizeof(char);
    }
    // Load up the brand_adjacency_matrix
    for (int x = 0; x < MAT_SIZE; x++) {
        fscanf(f, "%s", buff);
        for (int y = 0; y < MAT_SIZE; y++) {
            int value = (int) buff[y*2];
            if (value == 48) { value = 0; }
            else {value = 1;}
            brand_adjacency_matrix[x][y] = value;
        }
    }
}


// Users
/**TODO: Complete this function
 * Creates and returns a user. Returns NULL on failure.
 **/
User* create_user(char* name){
  User *node = calloc(sizeof(User),1);
  strcpy(node->name, name);
  node->friends = NULL;
  node->brands = NULL;
  node->visited = false;

  // add into all user
  allUsers = insert_into_friend_list(allUsers, node);
  return node;
}

/**TODO: Complete this function
 * Deletes a given user. 
 * Returns 0 on success, -1 on failure.
 **/

int delete_user(User* user){

  // a.  remove user from allUser's frident list
  FriendNode * my_friend = user->friends;
  while( my_friend != NULL ) {
    my_friend->user->friends =  delete_from_friend_list(my_friend->user->friends, user);
    my_friend = my_friend->next;
  }

  // b.  remove user's frident list/brand list
  FriendNode * current_node = user->friends;
  while( current_node != NULL ) {
    FriendNode * temp = current_node->next;
    free(current_node);
    current_node = temp;
  }

  BrandNode * brand_node = user->brands;
  while( brand_node != NULL ) {
    BrandNode * temp = brand_node->next;
    free(brand_node);
    brand_node = temp;
  }

  // c.  free user
  allUsers = delete_from_friend_list(allUsers, user);
  free(user);

  return -1;
}

/**TODO: Complete this function
 * Create a friendship between user and friend.
 * Returns 0 on success, -1 on failure.
 **/
int add_friend(User* user, User* friend){
  user->friends = insert_into_friend_list(user->friends,friend);
  friend -> friends = insert_into_friend_list(friend->friends,user);

  if( in_friend_list(user->friends, friend) && in_friend_list(friend->friends, user) ){
    return 0;
  }
  return -1;
}

/**TODO: Complete this function
 * Removes a friendship between user and friend.
 * Returns 0 on success, -1 on faliure.
 **/
int remove_friend(User* user, User* friend){
  user->friends = delete_from_friend_list(user->friends,friend);
  friend -> friends = delete_from_friend_list(friend->friends,user);

  if(!in_friend_list(user->friends,friend) && !in_friend_list(friend -> friends,user)){
    return 0;
  }
  return -1;
}

/**TODO: Complete this function
 * Creates a follow relationship, the user follows the brand.
 * Returns 0 on success, -1 on faliure.
 **/
int follow_brand(User* user, char* brand_name){
  user->brands = insert_into_brand_list(user->brands,brand_name);
  if(in_brand_list(user->brands,brand_name)){
    return 0;
  }
  return -1;
}

/**TODO: Complete this function
 * Removes a follow relationship, the user unfollows the brand.
 * Returns 0 on success, -1 on faliure.
 **/
int unfollow_brand(User* user, char* brand_name){
  user->brands = delete_from_brand_list(user->brands,brand_name);
  if(!in_brand_list(user->brands,brand_name)){
    return 0;
  }
  return -1;
}

/**TODO: Complete this function
 * Return the number of mutual friends between two users.
 **/
int get_mutual_friends(User* a, User* b){
  int count = 0;
  for(FriendNode *b_friend = b->friends; b_friend != NULL; b_friend = b_friend->next){
      if(in_friend_list(a->friends,b_friend->user)){
        count++;
      }
    }
  return count;
}

/**TODO: Complete this function
 * A degree of connection is the number of steps it takes to get from
 * one user to another.
 * 
 * For example, if X & Y are friends, then we expect to recieve 1 when calling
 * this on (X,Y). Continuing on, if Y & Z are friends, then we expect to
 * recieve 2 when calling this on (X,Z).
 * 
 * Returns a non-negative integer representing the degrees of connection
 * between two users, -1 on failure.
 **/
int get_degrees_of_connection(User* a, User* b){
  FriendNode *current = allUsers;
  // set all visited into false in order that some accidentally set to true
  while(current != NULL){
    current->user->visited = false;
    current = current->next;
  }

  // check my friend list
  a->visited = true;
  int degree = 1;

  FriendNode * current_node =  insert_into_friend_list( NULL, a );
  FriendNode * new_level_list = NULL;
  do{
    new_level_list = NULL;
    while( current_node != NULL ) {

      if( in_friend_list( current_node->user->friends, b) ) {
        return degree;
      }
      current_node->user->visited = true;

      FriendNode * friend_node = current_node->user->friends;
      while( friend_node != NULL ) {
        if( friend_node->user->visited != true ) {
          if(!in_friend_list(new_level_list,friend_node->user)){
            new_level_list = insert_into_friend_list(new_level_list, friend_node->user );
          }
        }
        friend_node = friend_node->next;
      }
      current_node = current_node->next;
    }
    degree++;
    current_node = new_level_list;        
  }while ( new_level_list !=NULL );
  return -1;
}


// Brands
/**TODO: Complete this function
 * Marks two brands as similar.
 **/
void connect_similar_brands(char* brandNameA, char* brandNameB){
  int idx = get_brand_index(brandNameA);
  int idy = get_brand_index(brandNameB);

  brand_adjacency_matrix[idx][idy] = 1;
  brand_adjacency_matrix[idy][idx] = 1;
}
/**TODO: Complete this function
 * Marks two brands as not similar.
 **/
void remove_similar_brands(char* brandNameA, char* brandNameB){
  int idx = get_brand_index(brandNameA);
  int idy = get_brand_index(brandNameB);

  brand_adjacency_matrix[idx][idy] = 0;
  brand_adjacency_matrix[idy][idx] = 0;
}


// Harder ones
/**TODO: Complete this function
 * Returns a suggested friend for the given user, returns NULL on failure.
 * See the handout for how we define a suggested friend.
 **/
User* get_suggested_friend(User* user){
  int max = 0;
  int count;
  User *suggested = NULL;
  FriendNode *current = allUsers;
  while(current != NULL){
    count = 0;
    if(strcmp(current -> user->name,user->name) != 0 && !in_friend_list(user->friends,current->user)){
      for(BrandNode *brands = current->user->brands; brands != NULL; brands = brands->next){
        if(in_brand_list(user->brands,brands->brand_name)){
          count ++;
        }
      }
      if(count >= max){
        suggested = current->user;
        max = count;
      }
    }
    current = current -> next;
  }
  return suggested;
}

/**TODO: Complete this function
 * Friends n suggested friends for the given user.
 * See the handout for how we define a suggested friend.
 * Returns how many friends were successfully followed.
 **/
int add_suggested_friends(User* user, int n){
  User *friend = NULL;
  int count = 0;
  for(int i = 0; i < n; i++){
    friend = get_suggested_friend(user);
    if( friend == NULL )
      break;
    if(add_friend(user,friend) == 0){
      count++;
    }
  }
  return count;
}

int get_suggested_brand_id(User *user){  
  BrandNode* current = user->brands;
  int suggested_id = -1;
  int count = 0;
  int max = 1;

  for(int i = 0; i< MAT_SIZE;i++){
    char * current_brand = brand_names[i];

    count = 0;
    if( in_brand_list(user->brands, current_brand ))
      continue;

    for(int j = 0; j<MAT_SIZE;j++){
      if(brand_adjacency_matrix[i][j] == 1 && strcmp(brand_names[j],"") != 0 ){
        if( in_brand_list(user->brands, brand_names[j]) ) {
          count++;
        }
      }
    }

    if(count >= max){
      if( count == max && strcmp(brand_names[suggested_id], brand_names[i])<0 ) {
        suggested_id = i;
      }
      max = count;
    }
  }

  return suggested_id;
}

/**TODO: Complete this function
 * Follows n suggested brands for the given user.
 * See the handout for how we define a suggested brand.     
 * Returns how many brands were successfully followed. 	  	
 **/
int follow_suggested_brands(User* user, int n){
  int count = 0;
  char *suggested_brand = NULL;
  for(int i = 0;i<n;i++){
    int suggested_id = get_suggested_brand_id(user);
    if(suggested_id == -1 )
      break;

    suggested_brand = brand_names[suggested_id];
    if(follow_brand(user, suggested_brand)){
      count++;
    }
  }
  
  return count;
}
