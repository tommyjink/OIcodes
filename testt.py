import re
import os

def generate_novel_pages(txt_file_path, output_dir="novel_pages"):
    """
    从小说TXT文件生成极简网页
    
    参数:
        txt_file_path: 小说TXT文件路径
        output_dir: 生成的网页存放目录
    """
    # 创建输出目录
    os.makedirs(output_dir, exist_ok=True)
    
    # 读取小说内容
    with open(txt_file_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # 简单的章节分割，匹配"第X章"格式
    chapter_pattern = re.compile(r'第[零一二三四五六七八九十百千万\d]+章[^。,，\n]*')
    chapter_titles = chapter_pattern.findall(content)
    
    chapters = []
    
    if not chapter_titles:
        # 如果没有找到章节标题，整个内容作为一章
        chapters.append({
            "title": "全本",
            "content": content
        })
    else:
        # 分割内容为章节
        last_pos = 0
        for i, title in enumerate(chapter_titles):
            # 找到当前章节标题的位置
            start_pos = content.find(title, last_pos)
            if start_pos == -1:
                continue
                
            # 找到下一章标题的位置
            if i < len(chapter_titles) - 1:
                end_pos = content.find(chapter_titles[i+1], start_pos)
            else:
                end_pos = len(content)
                
            # 提取章节内容
            chapter_content = content[start_pos:end_pos]
            chapters.append({
                "title": title,
                "content": chapter_content
            })
            
            last_pos = end_pos
    
    # 生成索引页 (index.html)
    with open(os.path.join(output_dir, "index.html"), 'w', encoding='utf-8') as f:
        f.write("<html>\n")
        f.write("<head>\n")
        f.write("<meta charset='utf-8'>\n")
        f.write("<title>小说目录</title>\n")
        f.write("</head>\n")
        f.write("<body>\n")
        f.write("<h1>小说目录</h1>\n")
        f.write("<ul>\n")
        
        # 为每个章节创建链接
        for i, chapter in enumerate(chapters):
            f.write(f"  <li><a href='chapter_{i}.html'>{chapter['title']}</a></li>\n")
        
        f.write("</ul>\n")
        f.write("</body>\n")
        f.write("</html>\n")
    
    # 生成各章节页面
    for i, chapter in enumerate(chapters):
        with open(os.path.join(output_dir, f"chapter_{i}.html"), 'w', encoding='utf-8') as f:
            f.write("<html>\n")
            f.write("<head>\n")
            f.write("<meta charset='utf-8'>\n")
            f.write(f"<title>{chapter['title']}</title>\n")
            f.write("</head>\n")
            f.write("<body>\n")
            
            # 章节标题
            f.write(f"<h1>{chapter['title']}</h1>\n")
            
            # 章节内容（将换行转换为段落）
            paragraphs = chapter['content'].split('\n\n')
            for para in paragraphs:
                if para.strip():
                    # 替换单换行符为空格
                    para = para.replace('\n', ' ')
                    f.write(f"<p>{para}</p>\n")
            
            # 导航链接
            f.write("<p>\n")
            if i > 0:
                f.write(f"  <a href='chapter_{i-1}.html'>上一章</a> | ")
            f.write(f"  <a href='index.html'>返回目录</a>")
            if i < len(chapters) - 1:
                f.write(f" | <a href='chapter_{i+1}.html'>下一章</a>")
            f.write("\n</p>\n")
            
            f.write("</body>\n")
            f.write("</html>\n")
    
    print(f"已生成 {len(chapters) + 1} 个网页文件到 {output_dir} 目录")

if __name__ == "__main__":
    # 替换为你的小说TXT文件路径
    novel_txt_path = "your_novel.txt"
    generate_novel_pages(novel_txt_path)
    print("网页生成完成！")
    