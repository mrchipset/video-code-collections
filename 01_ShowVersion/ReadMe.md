# Qt实现自动拷贝资源文件到构建目录

利用Qmake的命令来实现在编译时将资源文件等附加内容拷贝到构建目录

知识点：
    利用DESTDIR确定可执行文件的输出路径
    利用$$QMAKE_POST_LINK来在编译完成后运行指令操作
    QMAKE_POST_LINK是指在链接程序后运行的指令


DESTDIR = $$clean_path($$OUT_PWD/bin)


# copies the given files to the destination directory
defineTest(copyToDestDir) {
    files = $$1
    dir = $$2
    # replace slashes in destination path for Windows
    win32:dir ~= s,/,\\,g

    for(file, files) {
        # replace slashes in source path for Windows
        win32:file ~= s,/,\\,g

        QMAKE_POST_LINK += $$QMAKE_COPY_DIR $$shell_quote($$file) $$shell_quote($$dir) $$escape_expand(\\n\\t)
    }
    export(QMAKE_POST_LINK)
}

copyToDestDir($$OTHER_FILES, $$DESTDIR)
message($$QMAKE_POST_LINK)