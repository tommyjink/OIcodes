# -*- coding: utf-8 -*-
from openai import OpenAI
import time

# ===================== 【全局配置（仅改这里即可）】 =====================
# 1. 基础API配置（通用，无需频繁改）
API_CONFIG = {
    "api_key": "sk-srpkctkzuqklttmwszpitdqsjjmcbhoibfpepuykewfkplne",
    "base_url": "Pro/deepseek-ai/DeepSeek-V3.1-Terminus",
    "model": "Pro/deepseek-ai/DeepSeek-V3"
}

# 2. 交互参数配置（控制对话节奏）
INTERACTIVE_CONFIG = {
    "max_rounds": 2,          # 总对话轮次（所有角色轮流算1轮）
    "type_speed": 0.0,       # 控制台打字速度（0=无延迟）
    "single_response_tokens": 600,  # 单角色单次发言最大字数
    "temperature": 0.85       # 回复随机性（越高越灵活）
}

# 3. 场景&角色核心配置（重点修改区）
# 示例1：圣贤对话场景（可直接用）
SCENARIO_CONFIG = {
    "scene_name": "诸子百家与东西方圣贤论道",  # 场景名称（控制台标题）
    "discussion_topic": "如何看待‘治世与修身’的关系？各流派各抒己见。",  # 讨论议题
    "characters": [  # 参与角色（可增删、调整顺序，数量无限制）
        {
            "name": "孔子",
            "role_prompt": "你是儒家创始人孔子，核心思想是‘仁、礼、中庸’，主张入世治国、克己复礼，发言引用《论语》，语气温和且有教化感，讨论以‘人伦、社会秩序’为核心。"
        },
        {
            "name": "老子",
            "role_prompt": "你是道家创始人老子，核心思想是‘道、无为、自然’，主张出世顺道，反对人为干预，发言引用《道德经》，语气玄奥、简约，强调‘道法自然’。"
        },
        {
            "name": "如来佛祖",
            "role_prompt": "你是释迦牟尼如来佛祖，核心思想是‘缘起、空性、慈悲、涅槃’，主张破除执念、普度众生，发言充满禅理，语气平和、圆融。"
        },
        {
            "name": "耶稣",
            "role_prompt": "你是基督教的耶稣，核心思想是‘博爱、宽恕、救赎’，主张爱人如己、忍耐谦卑，发言引用圣经教义，语气慈悲、平和，强调灵魂与信仰。"
        }
    ]
}

# 示例2：职场讨论场景（替换上面的SCENARIO_CONFIG即可用）
# SCENARIO_CONFIG = {
#     "scene_name": "互联网公司产品研发讨论会",
#     "discussion_topic": "新功能需求紧急，产品要求一周上线，研发认为时间不足，各方商讨解决方案。",
#     "characters": [
#         {
#             "name": "产品经理",
#             "role_prompt": "你是互联网公司的产品经理，主张优先上线新功能，强调用户体验和市场抢占，语气激进，会反驳研发的保守观点。"
#         },
#         {
#             "name": "研发负责人",
#             "role_prompt": "你是研发负责人，主张先优化代码质量和测试，反对仓促上线，强调系统稳定性，会指出产品经理需求的不合理性。"
#         },
#         {
#             "name": "项目经理",
#             "role_prompt": "你是项目经理，中立协调，平衡进度和质量，会给出具体的折中方案，引导双方达成共识。"
#         },
#         {
#             "name": "测试负责人",
#             "role_prompt": "你是测试负责人，关注功能稳定性和用户体验，主张充分测试，反对无测试上线，语气严谨。"
#         },
#         {
#             "name": "CEO",
#             "role_prompt": "你是公司CEO，关注商业价值和市场节奏，平衡成本与效率，最终拍板决策，语气权威、简洁。"
#         }
#     ]
# }

# ===================== 【核心逻辑（无需修改）】 =====================
class MultiCharacterDialogue:
    """多角色对话核心类（封装所有逻辑，拓展性极强）"""
    def __init__(self, api_config, interactive_config, scenario_config):
        # 初始化配置
        self.client = OpenAI(
            api_key=api_config["api_key"],
            base_url=api_config["base_url"]
        )
        self.model = api_config["model"]
        self.max_rounds = interactive_config["max_rounds"]
        self.type_speed = interactive_config["type_speed"]
        self.max_tokens = interactive_config["single_response_tokens"]
        self.temperature = interactive_config["temperature"]
        
        self.scene_name = scenario_config["scene_name"]
        self.topic = scenario_config["discussion_topic"]
        self.characters = scenario_config["characters"]  # 角色列表（数量任意）
        self.character_names = [char["name"] for char in self.characters]
        
        # 初始化每个角色的对话历史（仅存储用户输入/AI回复，不含system）
        self.dialogue_histories = {char["name"]: [] for char in self.characters}

    def stream_response(self, character_name, character_prompt, context):
        """通用流式回复函数（适配任意角色）"""
        # 拼接system预设和上下文
        full_messages = [{"role": "system", "content": character_prompt}] + context
        print(f"\n{character_name}：", end="", flush=True)
        
        full_response = ""
        try:
            response = self.client.chat.completions.create(
                model=self.model,
                messages=full_messages,
                stream=True,
                temperature=self.temperature,
                max_tokens=self.max_tokens
            )
            # 流式输出（模拟打字）
            for chunk in response:
                if not chunk.choices:
                    continue
                if chunk.choices[0].delta.content:
                    content = chunk.choices[0].delta.content
                    full_response += content
                    print(content, end="", flush=True)
                    time.sleep(self.type_speed)
            print()  # 换行分隔
            return full_response
        except Exception as e:
            print(f"\n{character_name} 发言出错：{str(e)}")
            return ""

    def start_dialogue(self):
        """启动多角色对话"""
        # 打印场景标题
        print("=" * 120)
        print(f"【{self.scene_name}：{self.topic}】")
        print("=" * 120)
        
        # 若没有角色，直接退出
        if not self.characters:
            print("⚠️  未配置任何角色，对话终止！")
            return
        
        # 第一轮：第一个角色先基于议题发言
        first_char = self.characters[0]
        first_name = first_char["name"]
        first_prompt = first_char["role_prompt"]
        # 初始化第一个角色的上下文（议题作为初始输入）
        self.dialogue_histories[first_name] = [{"role": "user", "content": self.topic}]
        prev_response = self.stream_response(first_name, first_prompt, self.dialogue_histories[first_name])
        if not prev_response:
            print("⚠️  首个角色发言失败，对话终止！")
            return
        
        # 多轮循环对话（所有角色轮流发言为1轮）
        for round_num in range(1, self.max_rounds + 1):
            print(f"\n--- 第{round_num + 1}轮讨论 ---")
            
            # 遍历除第一个外的所有角色，依次回应上一个角色的发言
            for i in range(1, len(self.characters)):
                current_char = self.characters[i]
                current_name = current_char["name"]
                current_prompt = current_char["role_prompt"]
                
                # 将上一个角色的发言加入当前角色的上下文
                self.dialogue_histories[current_name].append({"role": "user", "content": prev_response})
                # 当前角色发言
                current_response = self.stream_response(current_name, current_prompt, self.dialogue_histories[current_name])
                
                if not current_response:
                    print(f"⚠️  {current_name} 发言失败，对话提前终止！")
                    return
                
                # 更新上一个回复，供下一个角色使用
                prev_response = current_response
            
            # 第一轮结束后，第一个角色回应最后一个角色的发言（形成闭环）
            if round_num < self.max_rounds:
                self.dialogue_histories[first_name].append({"role": "user", "content": prev_response})
                prev_response = self.stream_response(first_name, first_prompt, self.dialogue_histories[first_name])
                if not prev_response:
                    print(f"⚠️  {first_name} 回应失败，对话提前终止！")
                    return
        
        # 对话结束
        print("\n" + "=" * 120)
        print(f"【{self.scene_name} 讨论结束】")
        print("=" * 120)

# ===================== 【启动入口（无需修改）】 =====================
if __name__ == "__main__":
    # 初始化对话实例（仅传入配置，无需改逻辑）
    dialogue = MultiCharacterDialogue(
        api_config=API_CONFIG,
        interactive_config=INTERACTIVE_CONFIG,
        scenario_config=SCENARIO_CONFIG
    )
    # 启动对话
    dialogue.start_dialogue()