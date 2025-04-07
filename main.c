#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Student {
  char name[10];
  int points[13];
  int sum;
  float avg;
};

int calculate_sum(struct Student *s) {
  int sum = 0;
  int points_count = sizeof(s->points)/sizeof(int);

  for (int i = 0; i < points_count; i++) {
    sum += s->points[i];
  }

  return sum;
}

float calculate_average(struct Student *s) {
  int points_count = sizeof(s->points)/sizeof(int);
  // int sum = calculate_sum(s);
  return (float)s->sum / (float)points_count;
}

float calculate_total_average(struct Student students[], int count) {
  float sum = 0.0;

  for (int i = 0; i < count; i++) {
    sum += students[i].avg;
  }

  return sum / (float)count;
}

void print_points(struct Student *s) {
  for (int i = 0; i < 13; i++) {
    printf("%d ", s->points[i]);
  }
}

void print_student(struct Student *s) {
    printf("%s %.1f\n", s->name, s->avg);
}

void input(struct Student *s) {
  char name[10];
  scanf("%s", &name);
  
  // Capitalize name
  name[0] = toupper(name[0]);

  // Set name
  strcpy(s->name, name);

  for (int i = 0; i < 13; i++) {
    // Capture point
    scanf("%d", &s->points[i]);
  }

  // Update sum
  s->sum = calculate_sum(s);
  
  // Update average
  s->avg = calculate_average(s); 
}

void print_top_student(struct Student students[], int len) {
  float max_avg = 0.0;
  char top[10];

  for (int i = 0; i < len; i++) {
    struct Student s = students[i];
    if (s.avg > max_avg) {
      strcpy(top, s.name);
      max_avg = s.avg;
    }
  }

  printf("%s\n", top);
}

void print_below_avg_students(struct Student students[], int len) {
  float total_avg = calculate_total_average(students, len);

  for (int k = 0; k < len; k++) {
    if (students[k].avg < total_avg) {
      printf("%s\n", students[k].name);
    }
  }
}

int main() {

  int NUM_OF_STUDENTS = 5;
  
  struct Student students[NUM_OF_STUDENTS];

  for (int i = 0; i < NUM_OF_STUDENTS; i++) {
    input(&students[i]);
  }

  print_top_student(students, NUM_OF_STUDENTS);

  print_below_avg_students(students, NUM_OF_STUDENTS);
  
  return 0;
}

