import asyncio
import os
from pyppeteer import launch

async def save_page_as_pdf(url, pdf_path):
    browser = await launch(headless=True)
    page = await browser.newPage()
    try:
        await page.goto(url, waitUntil='networkidle2')
        await page.pdf({
            'path': pdf_path,
            'format': 'A4',
            'printBackground': True,
            'displayHeaderFooter': False
        })
        print(f'成功保存 {pdf_path}')
    except Exception as e:
        print(f'保存 {pdf_path} 失败: {e}')
    finally:
        await browser.close()

async def generate_pdfs():
    start_num = 1000
    end_num = 5440
    base_url = 'http://218.201.91.220:8088/JudgeOnline/'
    pdf_dir = 'pdf'
    # 创建 pdf 目录，如果不存在的话
    if not os.path.exists(pdf_dir):
        os.makedirs(pdf_dir)

    for num in range(start_num, end_num + 1):
        url = f'{base_url}{num}.html'
        pdf_name = os.path.join(pdf_dir, f'pdf_{num}.pdf')
        if os.path.exists(pdf_name):
            print(f'跳过 {pdf_name}，文件已存在')
            continue
        await save_page_as_pdf(url, pdf_name)


if __name__ == '__main__':
    asyncio.get_event_loop().run_until_complete(generate_pdfs())