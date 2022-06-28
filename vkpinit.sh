#! /bin/bash

CMAKE_LISTS_TEXT="cmake_minimum_required(VERSION 3.14)\n
\n
set(PROJECT_NAME base)\n
project(\${PROJECT_NAME})\n
\n
add_executable(\${PROJECT_NAME}\n
	src/main.c\n
	)\n
set(GLFW_BUILD_DOCS OFF CACHE BOOL \"\" FORCE)\n
set(GLFW_BUILD_TESTS OFF CACHE BOOL \"\" FORCE)\n
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL \"\" FORCE)\n
add_subdirectory(external/glfw)\n
target_link_libraries(\${PROJECT_NAME} PUBLIC glfw)\n
\n
set_target_properties(\${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY \${CMAKE_BINARY_DIR}/bin/)\n
\n
add_custom_command(TARGET \${PROJECT_NAME} PRE_BUILD COMMAND \${CMAKE_COMMAND} -E copy_directory \${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:\${PROJECT_NAME}>/res)"

MAINC_TEXT="#include <GLFW/glfw3.h>\n
\n
int main(void)\n
{\n
\tGLFWwindow* window;\n
\n
\t/* Initialize the library */\n
\tif (!glfwInit())\n
\t\treturn -1;\n
\n
\t/* Create a windowed mode window and its OpenGL context */\n
\twindow = glfwCreateWindow(640, 480, \"Hello World\", NULL, NULL);\n
\tif (!window)\n
\t{\n
\t\tglfwTerminate();\n
\t\treturn -1;\n
\t}\n
\n
\t/* Make the window's context current */\n
\tglfwMakeContextCurrent(window);\n
\n
\t/* Loop until the user closes the window */\n
\twhile (!glfwWindowShouldClose(window))\n
\t{\n
\n
\t\t/* Swap front and back buffers */\n
\t\tglfwSwapBuffers(window);\n
\n
\t\t/* Poll for and process events */\n
\t\tglfwPollEvents();\n
\t}\n
\n
\tglfwTerminate();\n
\treturn 0;\n
}"

CWD=$(pwd)

GIT=git
GLFW_REPO=git@github.com:glfw/glfw.git

EXT_DIR=external
SRC_DIR=src
BLD_DIR=build
RES_DIR=res

mkdir ${EXT_DIR}
mkdir ${SRC_DIR}
mkdir ${BLD_DIR}
mkdir ${RES_DIR}

${GIT} init
echo "I AM PLACEHOLDER\n" > README.MD
echo "build" > .gitignore
echo -e ${CMAKE_LISTS_TEXT} > CMakeLists.txt
echo -e ${MAINC_TEXT} > ${SRC_DIR}/main.c
${GIT} add .
${GIT} commit -m "the big boom"

${GIT} remote add glfw ${GLFW_REPO}
${GIT} subtree add --prefix=${EXT_DIR}/glfw glfw master --squash
